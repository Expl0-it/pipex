/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:44:56 by mamichal          #+#    #+#             */
/*   Updated: 2024/08/09 20:11:17 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <fcntl.h>

int	get_infile(t_pipex *p_pipex, char **argv)
{
	if (true == p_pipex->here_doc)
	{
		handle_here_doc(); // TODO:
		p_pipex->in_fd = open(); // TODO: add valid file
	}
	else if (true == p_pipex->urandom)
	{
		handle_urandom(); // TODO:
		p_pipex->in_fd = open(); // TODO: add valid file
	}
	else
	{
		if (-1 == access(argv[1], F_OK))
		{
			// TODO: PRINT ENOENT ERROR
			p_pipex->invalid_infile = true;
			p_pipex->in_fd = open(); // TODO: add valid file
		}
		else
			p_pipex->in_fd = open(argv[1], O_RDONLY);
	}
	return (p_pipex->in_fd);
}
