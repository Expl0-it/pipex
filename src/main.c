/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:30:02 by mamichal          #+#    #+#             */
/*   Updated: 2024/09/02 12:00:04 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// @brief init with default values
static void	init_pipex(t_pipex *p_pipex)
{
	p_pipex->in_fd = -1;
	p_pipex->out_fd = -1;
	p_pipex->here_doc = false;
	p_pipex->invalid_infile = false;
	p_pipex->urandom = false;
	p_pipex->cmd_paths = NULL;
	p_pipex->cmd_args = NULL;
	p_pipex->cmd_count = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	t_pipex	*p_pipex;
	int		i;

	if (argc < 5)
		exit(NOT_ENOUGH_ARGS);
	p_pipex = &pipex;
	init_pipex(p_pipex);
	if (false == parse_args(p_pipex, argc, argv))
		return (cleanup(p_pipex) + ERR_ARGS);
	if (false == parse_cmd_paths(p_pipex, argc, argv, envp))
		return (cleanup(p_pipex) + ERR_PATHS);
	if (false == parse_cmd_args(p_pipex, argc, argv))
		return (cleanup(p_pipex) + ERR_CMD_ARGS);
	i = -1;
	while (++i < pipex.cmd_count)
		if (false == handle_child(p_pipex, i, envp))
			return (cleanup(p_pipex), ERR_PIPE_FORK);
	i = -1;
	while (++i < pipex.cmd_count)
		wait(NULL);
	return (cleanup(p_pipex), OK);
}
