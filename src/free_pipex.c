# include "../includes/pipex.h"

void	free_pipex(t_pipex **pipex)
{
	int	err_stat;
	int	i;
	
	i = -1;
	while ((*pipex)->cmd_1[++i])
		free((*pipex)->cmd_1[i]);
	free((*pipex)->cmd_1);
  //	Caso que el 2° comando falle, libero el 1° igualmente
	i = -1;
	while ((*pipex)->cmd_2[++i])
		free((*pipex)->cmd_2[i]);
	free((*pipex)->cmd_2);
	err_stat = close((*pipex)->fd_in);
	err_stat = close((*pipex)->fd_out);
	i = -1;
	while ((*pipex)->path[++i])
		free((*pipex)->path[i]);
	free((*pipex)->path);
	if (err_stat == -1)
	{
		throw_error("Failed to close the file descriptor", 1);
	}
	free(*pipex);
}
