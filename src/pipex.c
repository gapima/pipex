/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima <glima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:51:01 by glima             #+#    #+#             */
/*   Updated: 2024/04/26 18:52:29 by glima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	init_cmd(t_pipex_data *c, int f)
{
	c->fd = f;
	c->path = 0;
	c->cmd = 0;
	c->ag[0] = 0;
}

static void	free_all(t_pipex_data *c, t_pipex_data *d)
{
	free_struct(c);
	free_struct(d);
}

static char	**get_path(char **ep)
{
	char	**ret;
	char	*env;
	int		i;

	i = -1;
	while (ep[++i])
	{
		if (!ft_strncmp(ep[i], "PATH=", PATH))
		{
			env = ft_substr(ep[i], START, ft_strlen(ep[i]));
			if (!env)
				return (NULL);
			ret = ft_split(env, ':');
			if (!ret)
			{
				free(env);
				return (NULL);
			}
			free (env);
			return (ret);
		}
	}
	return (NULL);
}

static int	get_cmd(char **ep, t_pipex_data *c, char *cmd)
{
	int		i;
	char	**tmp;

	i = -1;
	c->path = get_path(ep);
	if (!c->path)
		return (0);
	tmp = ft_split(cmd, ' ');
	if (!tmp)
		return (0);
	c->cmd = ft_substr(tmp[i + 1], 0, ft_strlen(tmp[i + 1]) - 1);
	if (!c->cmd)
		return (free_arr(tmp));
	while (tmp[++i])
	{
		c->ag[i] = ft_substr(tmp[i], 0, ft_strlen(tmp[i]) - 1);
		if (!c->ag[i])
		{
			free_arr(c->ag);
			return (free_arr(tmp));
		}
	}
	c->ag[i] = 0;
	free_arr(tmp);
	return (1);
}

void	pipex(int f1, int f2, char **ag, char **envp)
{
	t_pipex_data	cmd1;
	t_pipex_data	cmd2;

	init_cmd(&cmd1, f1);
	init_cmd(&cmd2, f2);
	if (!get_cmd(envp, &cmd1, ag[2]) || !get_cmd(envp, &cmd2, ag[3]))
		return (free_all(&cmd1, &cmd2));
	if (!check_cmd(&cmd1) || !check_cmd(&cmd2))
		return (free_all(&cmd1, &cmd2));
	exec_cmd(&cmd1, &cmd2, envp);
	free_struct(&cmd1);
	free_struct(&cmd2);
}
