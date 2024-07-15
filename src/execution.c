#include "../includes/pipex.h"

int		exec_pipes(t_pipex *pipex, char **envp)
{
	pid_t	child_pid;
	int		status;

	//dprintf(2, "Check errors 3\n");
	child_pid = fork();
	//dprintf(2, "Check errors 4\n");
	if (child_pid == -1)
		throw_error("Pipe creation error", 1);
	//dprintf(2, "Check errors 5\n");
	if (child_pid == 0)
	{
//		if (pipex->cmd_1_is_exec == 1)
		{
			exec_first_child(pipex, envp);
			free(pipex->cmd_1[0]);
			free(pipex->cmd_1);
		}
	}
	/*if (flag == 1)
		exit(1);*/
	else
	{
		//wait(NULL);
		//wait(&return_code);
		//dprintf(2, "Check errors 7\n");
		close(pipex->pipe_fd[STD_WRITE]);
//		wait(&status);
		//dprintf(2, "Check errors 8\n");
		//close(pipex->pipe_fd[STD_WRITE]);
		//dprintf(2, "Check errors 9\n");
		child_pid = fork();
		//dprintf(2, "Check errors 10\n");
		if (child_pid == -1)
			throw_error("Child process creation error", 1);
		//dprintf(2, "Check errors 11\n");
		/*if(wait(&status) == -1)
			  throw_error("Error in the wait() function of the first child", 1);*/
		if (child_pid == 0)
		{
			//No ejecutar execve con cosas mal!!
		//dprintf(2, "Check errors 12\n");
//			if (pipex->cmd_2_is_exec == 1)
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
		//dprintf(2, "Check errors 13\n");
			//if(wait(&status) == -1)
			if (waitpid(child_pid, &status, 0) == -1)
			  throw_error("Error in the wait() function of the second child", 1);
		}
		//dprintf(2, "Check errors 14\n");
	}
	return (status);
}
