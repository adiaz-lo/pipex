# include "../includes/pipex.h"

//Delete cmd, because it's never used
int		check_command_access(t_pipex *pipex, char *cmd, char **envp)
{
	int		i;
	int		status;
	char	*path_plus_cmd;
	char	*aux_path_plus_cmd;

	i = 0;
	while (pipex->path[i])
	{
		aux_path_plus_cmd = ft_strjoin(pipex->path[i], "/");
		path_plus_cmd = ft_strjoin(aux_path_plus_cmd, pipex->cmd_1[0]);
		free(aux_path_plus_cmd);
		printf("Join: %s\n", path_plus_cmd);
		status = access(path_plus_cmd, X_OK);
//		path_plus_cmd = ft_split();
		if (status == 0)
		{
//			execve(path_plus_cmd, &cmd, envp);
			printf("Path found");
			free(path_plus_cmd);
			return (0);
		}
		free(path_plus_cmd);
		i++;
	}
	if (status == -1)
		throw_error("You don't have access to that command");
	return (status);
}
