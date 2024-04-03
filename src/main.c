#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex_data	pipex;

	if (ac != 5)
	{
		ft_printf("Invalid Command. Exemplo: ""./pipex <infile> <cmd1> <cmd2> <outfile>""\n");
		return (EXIT_FAILURE);
	}
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile == -1)
	{
		ft_printf("Invalid file input.\n");
		return (EXIT_FAILURE);
	}
	pipex.outfile = open(av[4], O_TRUNC | O_CREAT | O_WRONLY, 0777);
	if (pipex.outfile == -1)
	{
		close(pipex.infile);
		//				error_check(1, NULL); preciso criar essa função
	}
	// pid_init(argv, envp, &pipex);
	// free_tab(pipex.all_paths);
	// criar essas functions.
	return (0);
}

static	void	get_path(char **envp, t_pipex_data *pipex)
{
	int		i;
	char	**temp;

	i = 0;
	while (envp[i] != NULL && ft_strncmp("PATH", envp[i], 4) != 0)
		i++;
//	temp = ft_split(&envp[i][5], ':'); preciso adicionar minha split.
	i = 0;
	while (temp[i] != NULL)
		i++;
//	pipex->all_paths = malloc(sizeof(char *) * (i + 1)); preciso criar essa variavel all_paths
	// if (pipex->all_paths == NULL)
	// {
	// 	free_tab(temp);
	// 	exit(1);
	// }
	i = -1;
	//while (temp[++i] != NULL)
		//pipex->all_paths[i] = ft_strjoin(temp[i], "/");
	//pipex->all_paths[i] = NULL;
	//free_tab(temp); preciso criar essa função
}