/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:23:24 by adiaz-lo          #+#    #+#             */
/*   Updated: 2024/07/17 22:31:11 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	int	exec_pipes_2(t_pipex *pipex, char **envp, pid_t child_pid)
{
	if (child_pid == -1)
		throw_error("Child process creation error", 1);
	if (child_pid == 0)
	{
		if (pipex->cmd_1_is_exec == 0)
			exec_first_child(pipex, envp);
		return (1);
	}
	return (0);
}

int	exec_pipes(t_pipex *pipex, char **envp)
{
	pid_t	child_pid_fst_child;
	pid_t	child_pid_snd_child;
	int		status;

	child_pid_fst_child = fork();
	if (exec_pipes_2(pipex, envp, child_pid_fst_child) == 0)
	{
		close(pipex->pipe_fd[STD_WRITE]);
		child_pid_snd_child = fork();
		if (child_pid_snd_child == -1)
			throw_error("Child process creation error", 1);
		if (child_pid_snd_child == 0)
			exec_second_child(pipex, envp);
		else
		{
			if (waitpid(child_pid_fst_child, &status, 0) == -1)
				throw_error("Error in the second child", 1);
			if (waitpid(child_pid_snd_child, &status, 0) == -1)
				throw_error("Error in the second child", 1);
		}
	}
	return (status);
}
