#include "../includes/pipex.h"

void	throw_error(char *str)
{
	perror(str);
	exit(1);
}
