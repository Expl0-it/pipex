/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:44:56 by mamichal          #+#    #+#             */
/*   Updated: 2024/08/16 13:25:53 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	read_line(char **line, int fd, char limiter)
{
	char	*buf;
	char	c;
	int		i;

	i = 0;
	if (fd < 0)
		return (-1);
	buf = ft_calloc(sizeof(char), BUF_SIZE);
	if (!buf)
		return (-1);
	while (read(fd, &c, 1) > 0 && c > 0 && c != limiter && i < (BUF_SIZE - 2))
		buf[i++] = c;
	buf[i] = '\n';
	buf[i + 1] = 0;
	*line = buf;
	return (i + 1);
}

int	get_infile(t_pipex *p_pipex, char **argv)
{
	if (true == p_pipex->here_doc)
	{
		handle_here_doc(); // TODO:
		p_pipex->in_fd = open(HERE_DOC_PATH, O_RDONLY);
	}
	else if (true == p_pipex->urandom)
	{
		handle_urandom(); // TODO:
		p_pipex->in_fd = open(URANDOM_PATH, O_RDONLY);
	}
	else
	{
		if (-1 == access(argv[1], F_OK))
		{
			// TODO: PRINT ENOENT ERROR
			p_pipex->invalid_infile = true;
			p_pipex->in_fd = open(ERROR_PATH, O_RDONLY | O_CREAT, 0644);
		}
		else
			p_pipex->in_fd = open(argv[1], O_RDONLY);
	}
	return (p_pipex->in_fd);
}

int	get_outfile(t_pipex *p_pipex, char **argv, int argc)
{
	if (true == p_pipex->here_doc)
		p_pipex->out_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		p_pipex->out_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	return (p_pipex->out_fd);
}
