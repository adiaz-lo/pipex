#ifndef PIPEX_H
# define PIPEX_H

// INCLUDES DECLARATION
# include "../libft/includes/libft.h"
# include <sys/wait.h>
# include <fcntl.h>

// Macros Declaration
# define ARGS_C	5
# define PATH_STR "PATH="
# define PATH_CHAR_NUM 5
# define DELIMITER ':'
# define SLASH "/"
# define STD_READ 0
# define STD_WRITE 1

// Struct Declaration
typedef struct s_pipex
{
	int 	fd_in;
	char	**cmd_1;
	char	**cmd_2;
	int		fd_out;
	char	**path;
	int		pipe_fd[2];
}t_pipex;

// Functions Declaration
t_pipex		*save_args(char **argv, char **envp);
void		print_paths(char **path);
int			main(int argc, char **argv, char **envp);
int			check_file(char *file_read);
int			check_args(int argc, char **argv);
char		**search_path(char **env);
void		throw_error(char *str, int i);
void		free_pipex(t_pipex **);
int			check_command_access(t_pipex *, char **cmd);
void		exec_first_child(t_pipex *, char **envp);
void		exec_second_child(t_pipex *, char **envp);
int			return_exec_code(int status);

#endif
