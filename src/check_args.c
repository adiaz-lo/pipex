#include "../includes/pipex.h"

static int		check_args_num(int argc)
{
	if (argc != ARGS_C)
	{
		throw_error("You haven't input enough arguments");
		return (1);
	}
	return (0);
}

int		check_file(char *file_read)
{
	int	fd;

	fd = open(file_read, O_RDONLY);
	if (fd == -1)
	{
		throw_error("File open error");
		return (1);
	}
	return (fd);
}

int				check_args(int argc, char **argv)
{
	if (!(check_args_num(argc)))
	{
		return (1);
	}
	if (!(check_file(argv[1])))
	{
		return (1);
		throw_error("File doesn't exist or you haven't got access to it");
	}
//	if (!(check_command_access()))
//		return (1);
//	if (!(search_path(envp)))
//	{
//			return (1);
//			perror("Path doesn't");
//	}
			return (0);
}
