/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:45:39 by adiaz-lo          #+#    #+#             */
/*   Updated: 2024/07/17 21:46:13 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		return_code;
	int		status;

	if (argc != 5)
		return (1);
	if (ft_strlen(argv[2]) == 0 || ft_strlen(argv[3]) == 0)
		return (1);
	pipex = save_args(argv, envp);
	if (pipex->fd_in != -1)
	{
		pipex->cmd_1_is_exec = check_command_access(pipex, pipex->cmd_1);
	}
	if (pipex->fd_out != -1)
		pipex->cmd_2_is_exec = check_command_access(pipex, pipex->cmd_2);
	if (pipe(pipex->pipe_fd) == -1)
		throw_error("Pipe creation error", 1);
	status = exec_pipes(pipex, envp);
	return_code = return_exec_code(status);
	free_pipex(&pipex);
	return (return_code);
}
