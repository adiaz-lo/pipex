/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:50:18 by adiaz-lo          #+#    #+#             */
/*   Updated: 2024/07/17 21:52:02 by adiaz-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**search_path(char **env)
{
	int		i;
	char	**path;
	char	*aux_str;

	i = 0;
	aux_str = NULL;
	path = NULL;
	while (env[i])
	{
		if (!(ft_strncmp(env[i], PATH_STR, PATH_CHAR_NUM)))
		{
			aux_str = ft_strtrim(env[i], PATH_STR);
			break ;
		}
		i++;
	}
	if (aux_str != NULL)
	{
		path = ft_split(aux_str, ':');
		free(aux_str);
	}
	return (path);
}
