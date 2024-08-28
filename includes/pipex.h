/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:51:07 by mamichal          #+#    #+#             */
/*   Updated: 2024/08/28 20:05:47 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// INCLUDES
# include "../libft/libft.h"
#include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

// PATHS
# define HERE_DOC_PATH ".here_doc_pipex"
# define URANDOM_OUT_PATH ".urandom_pipex"
# define ERROR_PATH ".error_pipex"

// CONSTS
# define BUF_SIZE 4096

// TYPE DECLARATIONS
typedef enum e_errors
{
	OK = 0,
	MALLOC_ERROR = 1,
	NOT_ENOUGH_ARGS = 2,
	ERR_ARGS = 3,
	ERR_PATHS = 4,
	ERR_CMD_ARGS = 5,
	ERR_PIPE_FORK = 6
}				t_errors;

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	bool	here_doc;
	bool	invalid_infile;
	bool	urandom;
	char	**cmd_paths;
	char	***cmd_args;
	int		cmd_count;
}				t_pipex;

// FUNCTION DECLARATIONS

// files.c
int		get_infile(t_pipex *p_pipex, char **argv);
int		get_outfile(t_pipex *p_pipex, char **argv, int argc);

// parse.c
bool	parse_args(t_pipex *p_pipex, int argc, char **argv);
bool	parse_cmd_paths(t_pipex *p_pipex, int argc, char **argv, char **envp);
bool	parse_cmd_args(t_pipex *p_pipex, int argc, char **argv);

// cleanup.c
void	free_arr(char **arr, int to_be_freed);
void	free_2d_arr(char ***arr, int to_be_freed);
int		cleanup(t_pipex *p_pipex);

// env_paths.c
char	*find_path(char *cmd, char **envp);

// process.c
bool	handle_child(t_pipex *p_pipex, int i, char **envp);

#endif
