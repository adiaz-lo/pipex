# include "../includes/pipex.h"

void	exec_first_child(t_pipex *pipex, char **envp)
{
	//int i;
//	close(pipex->pipe_fd[STD_READ]);
	dup2(pipex->fd_in, STDIN_FILENO);
	dup2(pipex->pipe_fd[STD_WRITE], STDOUT_FILENO);
	printf("Break\n");
	if (execve(pipex->cmd_1[0], pipex->cmd_1, envp) == -1)
	{
	//i = -1;
		/*while (pipex->cmd_1[++i])
			free(pipex->cmd_1[i]);
		free(pipex->cmd_1);*/
		//free_pipex(&pipex);
		throw_error("execve execution failure in the first child");
	}
}
