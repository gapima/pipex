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

int 	error(int type);
int 	chenck_empty_cmd(char *s);
int 	get_cmd(char **env, t_pipex_data *pipex, char *cmd);
int		free_arr(char **path);
int 	check_cmd(t_pipex_data *pipex);

char    **get_path(char **envp);

void	pipex(int infile, int outfile, char **ag, char **env);
void	free_struct(t_pipex_data *c);

#endif
