#include "pipex.h"

int		check_args(int argc, char **argv)
{
	if (!(check_args_num(argc)))
		return (1);
	if (!(check_file_exists(argv[1])))
		return (1);
	if (!(check_command_access(argv[2], argv[3])))
		return (1);

	




	if (argc < 5)
	{
		print_error("You haven't input enough arguments");
		return (1);
	}
	else
		if (argc > 5)
		{
			print_error("Your input has too many arguments");
			return (1);
		}
	return (0);
}
