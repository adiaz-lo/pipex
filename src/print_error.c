#include "../includes/pipex.h"

void	print_error_arg(char *msg, char *file_path)
{
	write(2, file_path, ft_strlen(file_path));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}
