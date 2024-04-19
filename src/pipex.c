#include "../includes/pipex.h"

t_pipex	*save_args(char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	pipex->fd_in = check_file(argv[1]);
	pipex->cmd_1 = ft_split(argv[2], ' ');
	pipex->cmd_2 = ft_split(argv[3], ' ');
	//pipex->fd_out = ft_atoi(argv[4]);		Preguntar a Cris por esto
	pipex->fd_out = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0700);
	pipex->path = search_path(envp);
	return (pipex);
}

void print_paths(char **path) {
	int		i;

	i = 0;
	while (path[i]) {
		//printf("%s\n", path[i]);
		i++;
	}
}

int	main (int argc, char **argv, char **envp)
{
	pid_t	child_pid;
	t_pipex	*pipex;
	int		*status_pid;

	if (!(check_args(argc, argv)))
		return (1);
	pipex = save_args(argv, envp);
	check_command_access(pipex, pipex->cmd_1, envp);
	check_command_access(pipex, pipex->cmd_2, envp);
	//dup();
	if (pipe(pipex->pipe_fd) == -1)
		throw_error("Pipe creation error");
	child_pid = fork();
	if (child_pid == -1)
		throw_error("Child process creation error");
	if (child_pid == 0)
		exec_first_child(pipex, envp);
	else
	{
		wait(status_pid);
		close(pipex->pipe_fd[STD_WRITE]);
		child_pid = fork();
		if (child_pid == -1)
			throw_error("Child process creation error");
		if (child_pid == 0)
			exec_second_child(pipex, envp);
		else
		{
			free_pipex(pipex);
			wait(status_pid);
		}
		//getchar();
	}
	return (0);
}
