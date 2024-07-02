/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:51:07 by mamichal          #+#    #+#             */
/*   Updated: 2024/07/02 12:59:36 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// INCLUDES
// TODO: DLEATE LATER AFTER ADDING PRINTF TO LIBFT
//# include "../libft/includes/ft_printf.h"
# include "../libft/libft.h"
# include <sys/types.h>

typedef enum e_errors
{
	OK = 0,
}				t_errors;

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		cmd_count;
	bool	here_doc;
	bool	invalid_file;
	char	**cmd_paths;
	char	***cmd_args;
}				t_pipex;

#endif
