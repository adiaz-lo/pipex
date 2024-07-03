#include "../includes/pipex.h"

int	main (int argc, char **argv, char **envp)
{
	pid_t	child_pid;
	t_pipex	*pipex;
	int		return_code;
	int		status;

	if (!(check_args(argc, argv)))
	{
		return (0);
	}
  //Protect env NULL
	pipex = save_args(argv, envp);
//	fprintf(stderr, "%p\n", &pipex->cmd_1);
//	printf("%p\n", &pipex->cmd_1);
	if (pipex->fd_in != -1)
		check_command_access(pipex, pipex->cmd_1); //Lanzar error y marcar para que no haga el execve
	if(pipex->fd_out != -1)
		check_command_access(pipex, pipex->cmd_2); //Lanzar error y marcar para que no haga el execve
	if (pipe(pipex->pipe_fd) == -1)
		throw_error("Pipe creation error", 1);
	child_pid = fork();
	if (child_pid == -1)
		throw_error("Child process creation error", 1);
	if (child_pid == 0)
	{
		exec_first_child(pipex, envp);
		free(pipex->cmd_1[0]);
		free(pipex->cmd_1);
	}
	/*if (flag == 1)
		exit(1);*/
	else
	{
		//wait(NULL);
		//wait(&return_code);
		wait(&status);
		close(pipex->pipe_fd[STD_WRITE]);
		child_pid = fork();
		if (child_pid == -1)
			throw_error("Child process creation error", 1);
		if (child_pid == 0)
		{
			//No ejecutar execve con cosas mal!!
			exec_second_child(pipex, envp);
			//free(pipex->cmd_2);
		}
		/*if (flag == 1)
			exit(1);*/
		else
		{
			/*free_pipex(&pipex);
			free(pipex->cmd_2);*/
			/*free(pipex->cmd_2[0]);
			free(pipex->cmd_2);*/
		//	free_pipex(&pipex);
			//wait(NULL);
			//wait(&return_code);
			//if(wait(&return_code);
			if(wait(&status) == -1)
			  throw_error("Error in the wait() function", 1);
		}
	}
	//return (return_code);
	//return (WEXITSTATUS(return_code));
	//return (WEXITSTATUS(status));
	return_code = return_exec_code(status);
	//fprintf(stderr, "Return code of the last command execution in the 2nd child was: %d\n", return_code);
	free_pipex(&pipex);
	return (return_code);
}
