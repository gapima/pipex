#include "../include/pipex.h"

int check_cmd(t_pipex_data *pipex)
{
   	int		i;
	char	*cmd;

	i = -1;
	while (pipex->path[++i])
	{
		cmd = ft_strjoin(pipex->path[i], pipex->cmd);
		if (!cmd)
			return (0);
		if (access(cmd, X_OK) != -1)
		{
			free(cmd);
			return (1);
		}			
		free(cmd);
	}	
	error_msg(pipex->cmd);
	return (0); 
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