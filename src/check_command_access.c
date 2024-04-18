# include "../includes/pipex.h"

int		check_command_access(t_pipex *pipex, char **cmd, char **envp)
{
	int		i;
	int		status;
	char	*path_plus_cmd;
	char	*aux_path_plus_cmd;

	i = 0;
	while (pipex->path[i])
	{
		aux_path_plus_cmd = ft_strjoin(pipex->path[i], "/");
		path_plus_cmd = ft_strjoin(aux_path_plus_cmd, cmd[0]);
		free(aux_path_plus_cmd);
		status = access(path_plus_cmd, X_OK);
		if (status == 0)
		{
			free(cmd[0]);
			cmd[0] = path_plus_cmd;
			return (0);
		}
		free(path_plus_cmd);
		i++;
	}
	free_pipex(pipex);
	throw_error("You don't have access to that command");
	return (status);
}
