#include "../includes/pipex.h"

int	main (int argc, char **argv, char **envp)
{
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
	dprintf(2, "Check errors\n");
	status = exec_pipes(pipex, envp);
	dprintf(2, "Exit status main is: %d\n", status);
	dprintf(2, "Check errors 2\n");
	//return (return_code);
	//return (WEXITSTATUS(return_code));
	//return (WEXITSTATUS(status));
	return_code = return_exec_code(status);
	//fprintf(stderr, "Return code of the last command execution in the 2nd child was: %d\n", return_code);
	free_pipex(&pipex);
	return (return_code);
}
