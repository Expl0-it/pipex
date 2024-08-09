/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:27:13 by mamichal          #+#    #+#             */
/*   Updated: 2024/08/09 20:09:32 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

bool	parse_args(t_pipex *p_pipex, int argc, char **argv)
{
	if (0 == argv[1] && ft_strncmp(argv[1], "here_doc", 9))
		p_pipex->here_doc = true;
	else if (0 == argv[1] && ft_strncmp(argv[1], "/dev/urandom", 13))
		p_pipex->urandom = true;
	if (argc < 5 + (int)p_pipex->here_doc)
		return (false);
	if ()
}
