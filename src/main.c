/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:30:02 by mamichal          #+#    #+#             */
/*   Updated: 2024/08/05 19:08:00 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// @brief init with default values
static void	init_pipex(t_pipex *p_pipex, char **argv)
{
	p_pipex->in_fd = -1;
	p_pipex->out_fd = -1;
	if (ft_strncmp(argv[1], "here_doc", 9))
		p_pipex->here_doc = true;
	else
		p_pipex->here_doc = false;
	p_pipex->invalid_infile = false;
	p_pipex->urandom = false;
	p_pipex->cmd_paths = NULL;
	p_pipex->cmd_args = NULL;
	p_pipex->cmd_count = 0;
}

int	main(int argc, char **argv)
{
	t_pipex	pipex;
	t_pipex	*p_pipex;
	
	p_pipex = &pipex;
	ft_init_pipex(p_pipex);
}
