/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:44:53 by adiaz-lo          #+#    #+#             */
/*   Updated: 2024/07/17 21:45:29 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_pipex(t_pipex **pipex)
{
	int	err_stat;
	int	i;

	i = -1;
	while ((*pipex)->cmd_1[++i])
		free((*pipex)->cmd_1[i]);
	free((*pipex)->cmd_1);
	i = -1;
	while ((*pipex)->cmd_2[++i])
		free((*pipex)->cmd_2[i]);
	free((*pipex)->cmd_2);
	err_stat = close((*pipex)->fd_in);
	err_stat = close((*pipex)->fd_out);
	i = -1;
	if (((*pipex)->path))
	{
		while ((*pipex)->path[++i])
			free((*pipex)->path[i]);
		free((*pipex)->path);
	}
	if (err_stat == -1)
	{
		throw_error("Failed to close the file descriptor", 1);
	}
	free(*pipex);
}
