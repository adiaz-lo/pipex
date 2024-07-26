/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_first_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:38:16 by adiaz-lo          #+#    #+#             */
/*   Updated: 2024/07/17 21:40:14 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec_first_child(t_pipex *pipex, char **envp)
{
	dup2(pipex->fd_in, STDIN_FILENO);
	dup2(pipex->pipe_fd[STD_WRITE], STDOUT_FILENO);
	if (execve(pipex->cmd_1[0], pipex->cmd_1, envp) == -1)
		throw_error("execve execution failure in the first child", 1);
}
