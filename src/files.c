/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:44:56 by mamichal          #+#    #+#             */
/*   Updated: 2024/09/02 10:53:47 by mamichal         ###   ########.fr       */
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

int	handle_here_doc(char *limiter)
{
	int		fd;
	char	*line;

	fd = open(HERE_DOC_PATH, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (-1);
	write(STDOUT_FILENO, "heredoc> ", 9);
	while (read_line(&line, STDIN_FILENO, '\n') > 0)
	{
		if (0 == ft_strncmp(line, limiter, ft_strlen(limiter))
			&& (ft_strlen(line) == ft_strlen(limiter) + 1))
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
		write(STDOUT_FILENO, "heredoc> ", 9);
	}
	return (0);
}

int	handle_urandom(void)
{
	int		tmp_fd;
	int		urandom_fd;
	char	*line;

	urandom_fd = open("/dev/urandom", O_RDONLY);
	if (urandom_fd < 0)
		return (-1);
	tmp_fd = open(URANDOM_OUT_PATH, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (tmp_fd < 0)
		return (-1);
	if (-1 == read_line(&line, urandom_fd, 0))
		return (-1);
	write(tmp_fd, line, ft_strlen(line));
	free(line);
	close(urandom_fd);
	return (0);
}

int	get_infile(t_pipex *p_pipex, char **argv)
{
	if (true == p_pipex->here_doc)
	{
		handle_here_doc(argv[2]);
		p_pipex->in_fd = open(HERE_DOC_PATH, O_RDONLY);
	}
	else if (true == p_pipex->urandom)
	{
		handle_urandom();
		p_pipex->in_fd = open(URANDOM_OUT_PATH, O_RDONLY);
	}
	else
	{
		if (-1 == access(argv[1], F_OK))
		{
			ft_putstr_fd("no such file or directory\n", STDERR_FILENO);
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
		p_pipex->out_fd = open(argv[argc - 1], \
					O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		p_pipex->out_fd = open(argv[argc - 1], \
					O_RDWR | O_CREAT | O_TRUNC, 0644);
	return (p_pipex->out_fd);
}
