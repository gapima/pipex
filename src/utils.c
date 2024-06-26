/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima <glima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:51:06 by glima             #+#    #+#             */
/*   Updated: 2024/04/26 18:51:08 by glima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*ft_join(char *dst, const char *src)
{
	char	*r;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	r = malloc(sizeof(char)
			* (ft_strlen(src) + ft_strlen(dst) + 1));
	if (!r)
		return (NULL);
	while (dst[++i])
		r[i] = dst[i];
	while (src[++j])
		r[i++] = src[j];
	r[i] = '\0';
	return (r);
}

static void	child_one(int *pipefd, t_pipex_data *c, char **envp)
{
	int		i;
	char	*cmd;

	i = -1;
	if (dup2(c->fd, STDIN_FILENO) < 0
		|| dup2(pipefd[1], STDOUT_FILENO) < 0)
		return (perror("Child one"));
	close(pipefd[0]);
	while (c->path[++i])
	{
		cmd = ft_join(c->path[i], c->cmd);
		if (!cmd)
			return ;
		if (execve(cmd, c->ag, envp) != -1)
		{
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		free(cmd);
	}
	exit(EXIT_FAILURE);
}

static void	child_two(int *pipefd, t_pipex_data *c, char **envp)
{
	int		i;
	char	*cmd;

	i = -1;
	if (dup2(c->fd, STDOUT_FILENO) < 0
		|| dup2(pipefd[0], STDIN_FILENO) < 0)
		return (perror("Child two"));
	close(pipefd[1]);
	while (c->path[++i])
	{
		cmd = ft_join(c->path[i], c->cmd);
		if (!cmd)
			return ;
		if (execve(cmd, c->ag, envp) != -1)
		{
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		free(cmd);
	}
	exit(EXIT_FAILURE);
}

void	exec_cmd(t_pipex_data *cmd1, t_pipex_data *cmd2, char **envp)
{
	int		status;
	int		pipefd[2];
	pid_t	p1;
	pid_t	p2;

	status = 0;
	pipe(pipefd);
	p1 = fork();
	if (p1 < 0)
		return (perror("Fork one"));
	if (!p1)
		child_one(pipefd, cmd1, envp);
	p2 = fork();
	if (p2 < 0)
		return (perror("Fork two"));
	if (!p2)
		child_two(pipefd, cmd2, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}

int	check_cmd(t_pipex_data *c)
{
	int		i;
	char	*cmd;

	i = -1;
	while (c->path[++i])
	{
		cmd = ft_join(c->path[i], c->cmd);
		if (!cmd)
			return (0);
		if (access(cmd, X_OK) != -1)
		{
			free(cmd);
			return (1);
		}			
		free(cmd);
	}
	error_msg(c->cmd);
	return (0);
}
