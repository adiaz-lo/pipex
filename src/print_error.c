/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:46:23 by adiaz-lo          #+#    #+#             */
/*   Updated: 2024/07/17 21:46:52 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_error_arg(char *msg, char *file_path)
{
	write(2, file_path, ft_strlen(file_path));
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}
