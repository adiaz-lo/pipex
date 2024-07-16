#include "../includes/pipex.h"

/**
 * This function checks the access to the command, plus mounts the path + command
 * returns 0 if it's got access, 1 if not
 */
int		check_command_access(t_pipex *pipex, char **cmd)
{
	int		i;
	char	*path_plus_cmd;
	char	*aux_path_plus_cmd;

	i = 0;
//	fprintf(stderr, "%p\n", &pipex->cmd_1);
	if (!access(cmd[0], X_OK))
		return (1);
	while (pipex->path[i])
	{
		aux_path_plus_cmd = ft_strjoin(pipex->path[i], SLASH);
		path_plus_cmd = ft_strjoin(aux_path_plus_cmd, cmd[0]);
		free(aux_path_plus_cmd);
		if (access(path_plus_cmd, X_OK) == 0)
		{
			free(cmd[0]);
			cmd[0] = path_plus_cmd;
			//dprintf(2, "Valor del comando post: %s\n", cmd[0]);
			return (0);
			//dprintf(2, "Valor del comando: %s\n", path_plus_cmd);
			//break;
		}
		//Comprobar acceso a permisos
		free(path_plus_cmd);
		i++;
	}
	return (1);
	//free_pipex(&pipex);
	//throw_error("You don't have access to that command", 0);
		/*if (status == 0)
		{
			//return (free(path_plus_cmd), 0);
		}*/
}
