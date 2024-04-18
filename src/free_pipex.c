# include "../includes/pipex.h"

void	free_pipex(t_pipex *pipex)
{
	int	err_stat;
	
	err_stat = close(pipex->fd_in);
	err_stat = close(pipex->fd_out);
	free(pipex->path);
	if (err_stat == -1)
	{
		throw_error("Failed to close the file descriptor");
	}
}
