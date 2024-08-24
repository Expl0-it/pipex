/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:07:13 by mamichal          #+#    #+#             */
/*   Updated: 2024/08/24 13:03:24 by mamichal         ###   ########.fr       */
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

char	**get_paths(char **envp)
{
	char	*path;

	path = get_env("PATH", envp);
	if (NULL == path)
		return (NULL);
	return (ft_split(path, ':'));
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*path;
	char	*full_path;

	if (0 == access(cmd, F_OK))
		return (ft_substr(cmd, 0, ft_strlen(cmd)));
	paths = get_paths(envp);
	if (NULL == paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], "/");
		if (NULL == path)
			return (free_arr(paths, -1), NULL);
		full_path = ft_strjoin(path, cmd);
		free(path);
		if (NULL == full_path)
			return (free_arr(paths, -1), NULL);
		if (0 == access(full_path, F_OK))
			return (free_arr(paths, -1), full_path);
		free(full_path);
	}
	return (free_arr(paths, -1), NULL);
}
