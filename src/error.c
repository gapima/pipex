#include "../include/pipex.h"
#include <stdlib.h>

int error(int type)
{
	if (type == 1)
		ft_putstr_fd("Invalid number of arguments\n", 2);
	if (type == 2)
		ft_putstr_fd("Invalid file\n", 2);
	if (type == 3)
		ft_putstr_fd("Command <cmd1> <cmd2> empty.\n", 2);
	return (EXIT_FAILURE);
}

int chenck_empty_cmd(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

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