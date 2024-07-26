/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:48:53 by adiaz-lo          #+#    #+#             */
/*   Updated: 2024/07/17 21:50:03 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/**
 * Initialize the control flags to a value different of 0, to avoid
 */

t_pipex	*save_args(char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	pipex->fd_in = check_infile(argv[1]);
	pipex->cmd_1 = ft_split(argv[2], ' ');
	pipex->cmd_1_is_exec = 42;
	pipex->cmd_2_is_exec = 42;
	pipex->cmd_2 = ft_split(argv[3], ' ');
	pipex->fd_out = check_outfile(argv[4]);
	pipex->i = 0;
	pipex->path = search_path(envp);
	return (pipex);
}
