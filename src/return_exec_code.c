/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_exec_code.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:47:04 by adiaz-lo          #+#    #+#             */
/*   Updated: 2024/07/17 21:48:41 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	return_exec_code(int status)
{
	int	return_code;

	return_code = WEXITSTATUS(status);
	if (return_code == 1)
		throw_error("Last command didn't end successfully", 1);
	else if (return_code == 127)
		throw_error("Last command doesn't exist", 127);
	return (return_code);
}
