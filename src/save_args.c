#include "../includes/pipex.h"

t_pipex	*save_args(char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	pipex->fd_in = check_file(argv[1]);
	pipex->cmd_1 = ft_split(argv[2], ' ');
	pipex->cmd_2 = ft_split(argv[3], ' ');
	pipex->fd_out = check_outfile(argv[4]);
	pipex->path = search_path(envp);
	return (pipex);
}
