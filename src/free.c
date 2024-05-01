/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glima <glima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:50:46 by glima             #+#    #+#             */
/*   Updated: 2024/04/26 18:50:48 by glima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	free_arr(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		free(path[i++]);
	if (path)
		free(path);
	return (0);
}

void	free_struct(t_pipex_data *c)
{
	int	i;

	i = 0;
	if (c->cmd)
		free(c->cmd);
	free_arr(c->path);
	while (c->ag[i])
		free(c->ag[i++]);
}

int	check_empty(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != ' ')
			return (0);
	}
	error_msg(s);
	return (1);
}

void	error_msg(char *c)
{
	write(2, "-bash: ", 7);
	write(2, c, ft_strlen(c));
	write(2, ": ", 2);
	write(2, "command not found\n", 18);
}
