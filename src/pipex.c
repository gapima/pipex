#include "../include/pipex.h"

static void init_cmd(t_pipex_data *pipex, int fd)
{
    pipex->fd = fd;
    pipex->cmd = 0;
    pipex->path = 0;
    pipex->ag[0] = 0;

}

static void	free_all(t_pipex_data *cmd1, t_pipex_data *cmd2)
{
	free_struct(cmd1);
	free_struct(cmd2);
}

char    **get_path(char **envp)
{
	char	**ret;
	char	*env;
	int		i;

    i = -1;
    while (envp[++i])
    {
        if (!ft_strncmp(envp[i], "PATH=", PATH))
        {
            env = ft_substr(envp[i], START, ft_strlen(envp[i]));
            if (!env)
                return (NULL);
            ret = ft_split(env, ':');
            if (!ret)
            {
                free(env);
                return (NULL);
            }
            free(env);
            return (ret);
        }
    }
    return (NULL);
}

int get_cmd(char **env, t_pipex_data *pipex, char *cmd)
{
    int		i;
	char	**tmp;

    i = -1;
    pipex->path = get_path(env);
    if (!pipex->path)
        return (0);
    tmp = ft_split(cmd, ' ');
    if (!tmp)
        return (0);
    pipex->cmd = ft_substr(tmp[i + 1], 0, ft_strlen(tmp[i + 1] - 1));
    if (!pipex->cmd)
        return (free_arr(tmp));
    while (tmp[++i])
    {
        pipex->ag[i] = ft_substr(tmp[i], 0, ft_strlen(tmp[i]) - 1);
        if (!pipex->ag[i])
        {
            free(pipex->ag);
            return (free_arr(tmp));
        }
    }
    pipex->ag[i] = 0;
    free_arr(tmp);
    return (1);
}

void pipex(int infile, int outfile, char **ag, char **env)
{
    t_pipex_data cmd1;
    t_pipex_data cmd2;

    init_cmd(&cmd1, infile);
    init_cmd(&cmd2, outfile);
    if (!get_cmd(env, &cmd1, ag[2]) || !get_cmd(env, &cmd2, ag[3]))
        return (free_all(&cmd1, &cmd2));
}