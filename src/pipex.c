#include "../includes/pipex.h"

int	main (int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		return_code;
	int		status;

//	dprintf(2, "argv[2] length: %lu\n", ft_strlen(argv[2]));
//	dprintf(2, "argv[3] length: %lu\n", ft_strlen(argv[3]));
	if (argc != 5)
		return (1);
	if (ft_strlen(argv[2]) == 0 || ft_strlen(argv[3]) == 0)
		return (1);
  //Protect env NULL
	pipex = save_args(argv, envp);
//	fprintf(stderr, "%p\n", &pipex->cmd_1);
//	printf("%p\n", &pipex->cmd_1);
	if (pipex->fd_in != -1)
	{
		dprintf(2, "cmd 1 length: %lu", ft_strlen(pipex->cmd_1[0]));
		if (ft_strlen(pipex->cmd_1[0]) == 0)
			return (1);

		pipex->cmd_1_is_exec = check_command_access(pipex, pipex->cmd_1); //Lanzar error y marcar para que no haga el execve
		//check_command_access(pipex, pipex->cmd_1); //Lanzar error y marcar para que no haga el execve
		//dprintf(2, "Cmd 1 is exec value is: %d\n", pipex->cmd_1_is_exec);
	}
	if(pipex->fd_out != -1)
	{
		dprintf(2, "cmd 2 length: %lu", ft_strlen(pipex->cmd_2[0]));
		if (ft_strlen(pipex->cmd_2[0]) == 0)
			return (1);
		pipex->cmd_2_is_exec = check_command_access(pipex, pipex->cmd_2); //Lanzar error y marcar para que no haga el execve
		//check_command_access(pipex, pipex->cmd_2); //Lanzar error y marcar para que no haga el execve
		//dprintf(2, "Cmd 2 is exec value is: %d\n", pipex->cmd_2_is_exec);
	}
	if (pipe(pipex->pipe_fd) == -1)
		throw_error("Pipe creation error", 1);
//	dprintf(2, "Check errors\n");
	status = exec_pipes(pipex, envp);
//	dprintf(2, "Exit status main is: %d\n", status);
//	dprintf(2, "Check errors 2\n");
	//return (return_code);
	//return (WEXITSTATUS(return_code));
	//return (WEXITSTATUS(status));
	return_code = return_exec_code(status);
	dprintf(2, "Exit status is: %d\n", return_code);
	//fprintf(stderr, "Return code of the last command execution in the 2nd child was: %d\n", return_code);
	free_pipex(&pipex);
	return (return_code);
}
