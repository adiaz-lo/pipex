/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command_access.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:36:29 by adiaz-lo          #+#    #+#             */
/*   Updated: 2024/07/17 22:41:59 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	int	mount_path(t_pipex *pipex, char **cmd)
{
	char	*path_plus_cmd;
	int		i;
	char	*aux_path_plus_cmd;

	i = 0;
	while (pipex->path[i])
	{
		aux_path_plus_cmd = ft_strjoin(pipex->path[i], SLASH);
		path_plus_cmd = ft_strjoin(aux_path_plus_cmd, cmd[0]);
		free(aux_path_plus_cmd);
		if (access(path_plus_cmd, X_OK) == 0)
		{
			free(cmd[0]);
			cmd[0] = path_plus_cmd;
			return (0);
		}
		free(path_plus_cmd);
		i++;
	}
	return (1);
}

/**
 * This function checks the access to the command, plus mounts the path + command
 * returns 0 if it's got access, 1 if not
 */
int	check_command_access(t_pipex *pipex, char **cmd)
{
	if (access(cmd[0], F_OK | X_OK) == 0 && cmd[0][0] == '/')
	{
		if (pipex->i == 0)
		{
			pipex->cmd_1_is_exec = 0;
			pipex->i++;
		}
		else
			pipex->cmd_2_is_exec = 0;
		return (0);
	}
	else
	{
		pipex->i++;
		return (mount_path(pipex, cmd));
	}
}
