#include "../includes/pipex.h"

void	throw_error(char *str, int i)
{
	perror(str);
	exit(i);
}
