/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:33:57 by adiaz-lo          #+#    #+#             */
/*   Updated: 2024/07/17 21:36:17 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_infile(char *file_read)
{
	int	fd;

	if (access(file_read, O_RDONLY) != 0)
	{
		print_error_arg("Input file permission error", file_read);
		return (-1);
	}
	else
	{
		fd = open(file_read, O_RDONLY);
		if (fd == -1)
		{
			print_error_arg("File open error", file_read);
			return (-1);
		}
		return (fd);
	}
}

int	check_outfile(char *file_write)
{
	int	fd;

	if (access(file_write, F_OK) == 0 && access(file_write, W_OK) != 0)
	{
		print_error_arg("Output file permission error", file_write);
		return (-1);
	}
	else
	{
		fd = open(file_write, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd == -1)
		{
			print_error_arg("Output file open error", file_write);
			return (-1);
		}
		return (fd);
	}
}
