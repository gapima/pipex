/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima <glima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:14:42 by glima             #+#    #+#             */
/*   Updated: 2024/04/26 17:14:44 by glima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

# define PATH 5
# define START 6

typedef struct s_pipex_data
{
	int		infile;
	int		outfile;
	char	*cmd;
	char	**path;
	char    *ag[100];
	int		fd;
}	t_pipex_data;

int		check_empty(char *s);
int		free_arr(char **path);
int 	check_cmd(t_pipex_data *pipex);

void	pipex(int infile, int outfile, char **ag, char **env);
void	free_struct(t_pipex_data *c);
void	error_msg(char *c);
void	exec_cmd(t_pipex_data *cmd1, t_pipex_data *cmd2, char **envp);
void	error_msg(char *c);

#endif
