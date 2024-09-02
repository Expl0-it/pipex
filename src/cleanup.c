/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:09:54 by mamichal          #+#    #+#             */
/*   Updated: 2024/09/02 15:20:57 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdlib.h>

// NOTE: free the array, if to_be_freed provided free n elements only
void	free_arr(char **arr, int to_be_freed)
{
	int	i;

	i = -1;
	if (-1 == to_be_freed)
		while (NULL != arr[++i])
			free(arr[i]);
	else
		while (++i < to_be_freed)
			if (NULL != arr[i])
				free(arr[i]);
	free(arr);
}

// NOTE: free the array, if to_be_freed provided free n elements only
void	free_2d_arr(char ***arr, int to_be_freed)
{
	int	i;

	i = -1;
	if (-1 == to_be_freed)
		while (arr[++i])
			free_arr(arr[i], -1);
	else
		while (++i < to_be_freed)
			if (arr[i])
				free_arr(arr[i], -1);
	free(arr);
}

int	cleanup(t_pipex *p_pipex)
{
	if (-1 != p_pipex->in_fd)
		close(p_pipex->in_fd);
	if (-1 != p_pipex->out_fd)
		close(p_pipex->out_fd);
	if (NULL != p_pipex->cmd_paths)
		free_arr(p_pipex->cmd_paths, p_pipex->cmd_count);
	if (NULL != p_pipex->cmd_args)
		free_2d_arr(p_pipex->cmd_args, p_pipex->cmd_count);
	if (true == p_pipex->here_doc)
		unlink(HERE_DOC_PATH);
	if (true == p_pipex->urandom)
		unlink(URANDOM_OUT_PATH);
	if (true == p_pipex->invalid_infile)
		unlink(ERROR_PATH);
	return (0);
}
