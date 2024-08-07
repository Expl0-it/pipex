/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:51:07 by mamichal          #+#    #+#             */
/*   Updated: 2024/08/07 13:51:44 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// INCLUDES
# include "../libft/libft.h"
#include <stdio.h>
# include <sys/types.h>

typedef enum e_errors
{
	OK = 0,
	MALLOC_ERROR = 1,
	NOT_ENOUGH_ARGS = 2 
}				t_errors;

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	bool	here_doc;
	bool	invalid_infile;
	bool	urandom;
	char	**cmd_paths;
	char	**cmd_args;
	int		cmd_count;
}				t_pipex;

#endif
