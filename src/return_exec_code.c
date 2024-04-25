#include "../includes/pipex.h"

int		return_exec_code(int status)
{
  int	return_code;

  return_code = WEXITSTATUS(status);
  if(return_code == 1)
	throw_error("Last command didn't end successfully");
  else if(return_code == 127)
	throw_error("Last command doesn't exist");
  return (return_code);
}
