#include "../includes/pipex.h"

char	**search_path(char **env)
{
	int		i;
	char	**path;
	char	*aux_str;

	i = 0;
	while(env[i])
	{
		if (!(ft_strncmp(env[i], PATH_STR, PATH_CHAR_NUM)))
		{
			aux_str = ft_strtrim(env[i], PATH_STR);
			break;
		}
		i++;
	}
	path = ft_split(aux_str, ':');
	return (path);
}
