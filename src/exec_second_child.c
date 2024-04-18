# include "../includes/pipex.h"

void	exec_second_child(t_pipex *pipex, char **envp)
{
	close(pipex->pipe_fd[STD_WRITE]);
//	dup2(pipex->pipe_fd[STD_READ], STDIN_FILENO);
//	dup2(pipex->fd_out, STDOUT_FILENO);
	printf("%d\n", pipex->pipe_fd[STD_READ]);
	printf("%d\n", pipex->fd_out);
	if (execve(pipex->cmd_2[0], pipex->cmd_2, envp) == -1)
	{
		printf("%d\n", pipex->fd_out);
		free_pipex(pipex);
		throw_error("execve execution failure");
	}
	printf("%d\n", pipex->fd_out);
	close(pipex->pipe_fd[STD_READ]);
}
