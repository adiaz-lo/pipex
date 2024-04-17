#ifndef PIPEX_H
# define PIPEX_H

// INCLUDES DECLARATION
# include "../libft/includes/libft.h"
# include <fcntl.h>

// Macros Declaration
# define ARGS_C	5
# define PATH_STR "PATH="
# define PATH_CHAR_NUM 5
# define DELIMITER ':'

// Struct Declaration
typedef struct s_pipex
{
	int fd_in;
	char **cmd_1;
	char *cmd_2;
	int	fd_out;
	char **path;
}t_pipex;

// Functions Declaration
t_pipex		*save_args(char **argv, char **envp);
void		print_paths(char **path);
int			main(int argc, char **argv, char **envp);
int			check_file(char *file_read);
int			check_args(int argc, char **argv);
char		**search_path(char **env);
void		throw_error(char *str);
void		free_pipex(t_pipex *);
int			check_command_access(t_pipex *, char *cmd, char **envp);

#endif
