#include "../includes/pipex.h"

t_pipex	*save_args(char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	pipex->fd_in = check_file(argv[1]);
	pipex->cmd_1 = ft_split(argv[2], ' ');
	pipex->cmd_2 = ft_split(argv[3], ' ');
	pipex->fd_out = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0700);
	pipex->path = search_path(envp);
	return (pipex);
}

int	main (int argc, char **argv, char **envp)
{
	pid_t	child_pid;
	t_pipex	*pipex;
	int		flag;
	//int		return_code;
	int		status;

	flag = 0;
	if (!(check_args(argc, argv)))
		return (1);
  //Protect env NULL
	pipex = save_args(argv, envp);
	flag |= check_command_access(pipex, pipex->cmd_1);
	flag |= check_command_access(pipex, pipex->cmd_2);
	if (pipe(pipex->pipe_fd) == -1)
		throw_error("Pipe creation error");
	child_pid = fork();
	if (child_pid == -1)
		throw_error("Child process creation error");
	if (child_pid == 0)
	{
		exec_first_child(pipex, envp);
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
			throw_error("Child process creation error");
		if (child_pid == 0)
		{
			exec_second_child(pipex, envp);
			free(pipex->cmd_2);
		}
		/*if (flag == 1)
			exit(1);*/
		else
		{
			free_pipex(&pipex);
			//wait(NULL);
			//wait(&return_code);
			//if(wait(&return_code);
			if(wait(&status) == -1)
			  throw_error("Error in the wait() function");
		}
	}
	//return (return_code);
	//return (WEXITSTATUS(return_code));
	return (WEXITSTATUS(status));
}
