/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_second_child.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:40:41 by adiaz-lo          #+#    #+#             */
/*   Updated: 2024/07/17 21:41:00 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec_second_child(t_pipex *pipex, char **envp)
{
	dup2(pipex->pipe_fd[STD_READ], STDIN_FILENO);
	dup2(pipex->fd_out, STDOUT_FILENO);
	if (pipex->fd_out == -1)
		exit(1);
	if (pipex->cmd_2_is_exec != 0)
		exit(127);
	if (execve(pipex->cmd_2[0], pipex->cmd_2, envp) == -1)
		throw_error("execve execution failure in the second child", 1);
}
