#include "../include/pipex.h"

int	main(int ac, char **argv, char **env)
{
	t_pipex_data pipex;
	(void)env;
	if (ac != 5)
		return(error(1));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile == -1)
	    return (error(2));
	pipex.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex.outfile == -1)
	{
		close(pipex.infile);
		return (error(2));
	}
	if (chenck_empty_cmd(argv[2]) == 1|| chenck_empty_cmd(argv[3]) == 1)
		return (error(3));
	return (0);
}
