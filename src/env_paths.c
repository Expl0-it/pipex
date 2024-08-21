/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:07:13 by mamichal          #+#    #+#             */
/*   Updated: 2024/08/21 19:22:20 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// @return name of env variable passed as key or NULL if doesn't exist
static char	*get_env(char *key, char **envp)
{
	int	i;
	int	key_len;

	key_len = ft_strlen(key);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(key, envp[i], key_len) == 0
				 && envp[i][key_len] == '=')
			return (ft_strchr(envp[i], '=') + 1);
		i++;
	}
	return (NULL);
}

char **get_paths(char **envp)
{
	char	*path;

	path = get_env("PATH", envp);
	if (NULL == path)
		return (NULL);
	return (ft_split(path, ':'));
}
