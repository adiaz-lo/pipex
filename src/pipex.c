#include "../includes/pipex.h"

t_pipex	*save_args(char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	pipex->fd_in = check_file(argv[1]);
	pipex->cmd_1 = ft_split(argv[2], ' ');
	pipex->cmd_2 = argv[3];
	pipex->fd_out = ft_atoi(argv[4]);
	pipex->path = search_path(envp);
	return (pipex);
}

void print_paths(char **path) {
	int		i;

	i = 0;
	while (path[i]) {
		printf("%s\n", path[i]);
		i++;
	}
}

int	main (int argc, char **argv, char **envp)
{
	//pid_t	child_pid;
	t_pipex	*pipex;
	char	**cmd_1;

	if (!(check_args(argc, argv)))
		return (1);
	pipex = save_args(argv, envp);
//	print_paths(pipex->path);
	cmd_1 = ft_split(argv[2], ' ');
	check_command_access(pipex, cmd_1[0], envp);
	free_pipex(pipex);

	return (0);
}
