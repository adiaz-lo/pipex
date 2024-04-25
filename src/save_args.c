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
