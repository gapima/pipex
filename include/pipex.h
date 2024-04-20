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
//int 	get_cmd(char **env, t_pipex_data *pipex, char *cmd);
int		free_arr(char **path);
int 	check_cmd(t_pipex_data *pipex);

//char    **get_path(char **envp);
char	**ft_splitpath(char *s, char c);

void	pipex(int infile, int outfile, char **ag, char **env);
void	free_struct(t_pipex_data *c);
void	error_msg(char *c);
void	exec_cmd(t_pipex_data *cmd1, t_pipex_data *cmd2, char **envp);
void	error_msg(char *c);


int	ft_putstr(char *s, char *t);
char	*ft_strdup(const char *src);
int	ft_putstr(char *s, char *t);
char	*ft_strdup(const char *src);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int	ft_strncmp(const char *s1, const char *s2, size_t n);


#endif
