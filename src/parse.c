/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:27:13 by mamichal          #+#    #+#             */
/*   Updated: 2024/09/02 10:44:36 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

bool	parse_args(t_pipex *p_pipex, int argc, char **argv)
{
	if (argv[1] && 0 == ft_strncmp(argv[1], "here_doc", 9))
		p_pipex->here_doc = true;
	else if (argv[1] && 0 == ft_strncmp(argv[1], "/dev/urandom", 13))
		p_pipex->urandom = true;
	if (argc < 5 + (int)p_pipex->here_doc)
		return (false);
	if (-1 == get_infile(p_pipex, argv))
		return (false);
	if (-1 == get_outfile(p_pipex, argv, argc))
		return (false);
	p_pipex->cmd_count = (argc - (3 + p_pipex->here_doc));
	return (true);
}

bool	parse_cmd_paths(t_pipex *p_pipex, int argc, char **argv, char **envp)
{
	int		i;
	char	**cmd;

	p_pipex->cmd_paths = ft_calloc(sizeof(char *), \
							(argc - 2 - p_pipex->here_doc));
	if (NULL == p_pipex->cmd_paths)
		return (false);
	i = 1 + p_pipex->here_doc;
	while (++i < (argc - 1))
	{
		cmd = ft_split(argv[i], ' ');
		if (!cmd)
		{
			free_arr(p_pipex->cmd_paths, (i - 2 - p_pipex->here_doc));
			p_pipex->cmd_paths = NULL;
			return (false);
		}
		p_pipex->cmd_paths[i - 2 - p_pipex->here_doc] = find_path(cmd[0], envp);
		free_arr(cmd, -1);
	}
	return (true);
}

bool	parse_cmd_args(t_pipex *p_pipex, int argc, char **argv)
{
	int		i;
	char	**cmd;

	p_pipex->cmd_args = ft_calloc(sizeof(char **), (argc - 2 - p_pipex->here_doc));
	if (NULL == p_pipex->cmd_args)
		return (false);
	i = 1 + p_pipex->here_doc;
	while (++i < (argc - 1))
	{
		cmd = ft_split(argv[i], ' ');
		if (NULL == cmd)
		{
			free_2d_arr(p_pipex->cmd_args, p_pipex->cmd_count);
			p_pipex->cmd_args = NULL;
			return (false);
		}
		p_pipex->cmd_args[i - 2 - p_pipex->here_doc] = cmd;
	}
	return (true);
}
