/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:42:51 by adiaz-lo          #+#    #+#             */
/*   Updated: 2024/07/17 22:49:50 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	**cmd_1;
	char	**cmd_2;
	int		fd_in;
	int		fd_out;
	char	**path;
	int		pipe_fd[2];
	int		cmd_1_is_exec;
	int		cmd_2_is_exec;
	int		i;
}	t_pipex;

// Functions Declaration
t_pipex	*save_args(char **argv, char **envp);
void	print_paths(char **path);
int		main(int argc, char **argv, char **envp);
int		check_infile(char *file_read);
int		check_outfile(char *file_read);
char	**search_path(char **env);
void	throw_error(char *str, int i);
void	free_pipex(t_pipex **pipex);
int		check_command_access(t_pipex *pipex, char **cmd);
void	exec_first_child(t_pipex *pipex, char **envp);
void	exec_second_child(t_pipex *pipex, char **envp);
int		return_exec_code(int status);
int		exec_pipes(t_pipex *pipex, char **envp);
void	print_error_arg(char *msg, char *file_path);

#endif
