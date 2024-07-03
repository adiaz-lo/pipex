# include "../includes/pipex.h"

void	exec_first_child(t_pipex *pipex, char **envp)
{
	//int i;
//	close(pipex->pipe_fd[STD_READ]);
	dup2(pipex->fd_in, STDIN_FILENO);
	close(pipex->fd_in);
	dup2(pipex->pipe_fd[STD_WRITE], STDOUT_FILENO);
	close(pipex->pipe_fd[STD_WRITE]);
	printf("Break\n");
	if (execve(pipex->cmd_1[0], pipex->cmd_1, envp) == -1)
	{
	//i = -1;
		/*while (pipex->cmd_1[++i])
			free(pipex->cmd_1[i]);
		free(pipex->cmd_1);*/
		//free_pipex(&pipex);
		//Perror capture with WIFEXIT, print it & exit(perror)
		throw_error("execve execution failure in the first child", 1);
	}
}
