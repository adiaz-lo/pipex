#include "../includes/pipex.h"

static int		check_args_num(int argc)
{
	if (argc != ARGS_C)
	{
		throw_error("You haven't input enough arguments", 1);
		return (0);
	}
	return (1);
}

int		check_infile(char *file_read)
{
	int	fd;

	//printf("wepaaa\n");
	if (access(file_read, R_OK) != 0) 
	{
		//printf("wepa2aa\n");
		return (-1);
	}
	else
	{
		fd = open(file_read, O_RDONLY);
		if (fd == -1)
		{
			throw_error("File open error", 0);
		}
		//printf("wepaaa\n");
		return (fd);
	}
}

int		check_outfile(char *file_write)
{
		int	fd;

	//printf("wepaaa\n");
	if (access(file_write, F_OK) == 0 && access(file_write, W_OK) != 0)
	{
		//printf("wepa2aa\n");
		return (-1);
	}
	else
	{
		fd = open(file_write, O_WRONLY | O_TRUNC | O_CREAT, 0777);
		if (fd == -1)
		{
			throw_error("File open error", -1);
		}
		//printf("wepaaa\n");
		return (fd);
	}

}

int			check_args(int argc, char **argv)
{
	int fd2;

	if ((check_args_num(argc)))
	{
		return (1);
	}
	fd2 = check_infile(argv[1]);
	printf("Bucle\n");
	if (fd2 == 0)
	{
		//printf("wepaaa\n");
		return (1);
		throw_error("File doesn't exist or you haven't got access to it", 1);
	}
	//printf("hshshd\n");
	return (0);
}
