#include "../includes/pipex.h"

int		return_exec_code(int status)
{
  int	return_code;

  return_code = WEXITSTATUS(status);
  if(return_code == 1)
	throw_error("Last command didn't end successfully", 1);
  else if(return_code == 127)
	throw_error("Last command doesn't exist", 127);
  dprintf(2, "Exit status is: %d\n", return_code);
  return (return_code);
}
