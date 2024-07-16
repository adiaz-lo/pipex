# include "../includes/pipex.h"

void	exec_second_child(t_pipex *pipex, char **envp)
{
	//close(pipex->pipe_fd[STD_WRITE]);
	dup2(pipex->pipe_fd[STD_READ], STDIN_FILENO);
	dup2(pipex->fd_out, STDOUT_FILENO);
	//close(pipex->pipe_fd[STD_READ]);
	if (pipex->fd_out == -1)
		exit(1);
	if (pipex->cmd_2_is_exec != 0)
		exit(127);
	if (execve(pipex->cmd_2[0], pipex->cmd_2, envp) == -1)
	{
		//free_pipex(&pipex);
		throw_error("execve execution failure in the second child", 1);
	}
}
