/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:16:28 by mamichal          #+#    #+#             */
/*   Updated: 2024/08/28 19:57:12 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

bool	pipe_fork(t_pipex *p_pipex, pid_t *p_pid, int fds[2], int i)
{
	if (-1 == pipe(fds))
		return (false);
	*p_pid = fork();
	if (-1 == *p_pid)
	{
		close(fds[0]);
		close(fds[1]);
		return (false);
	}
	if (0 == *p_pid)
	{
		if (0 == i)
			dup2(p_pipex->in_fd, STDIN_FILENO);
		if ((p_pipex->cmd_count - 1) == i)
			dup2(p_pipex->out_fd, STDOUT_FILENO);
		else
			dup2(fds[1], STDOUT_FILENO);
	}
	else
		dup2(fds[0], STDIN_FILENO);
	return (true);
}

bool	create_child(t_pipex *p_pipex, int i, char **envp)
{
	pid_t	pid;
	int		fds[2];

	if (false == pipe_fork(p_pipex, &pid, fds, i))
		return (false);
	if (pid == 0)
	{
		if (p_pipex->cmd_paths[i])
			execve(p_pipex->cmd_paths[i], p_pipex->cmd_args[i], envp);
		else
			ft_putstr_fd("pipex: one of provided arguments not found", 2);
		cleanup(p_pipex);
		exit(ERR_PATHS);
	}
	else
	{
		close(fds[0]);
		close(fds[1]);
	}
	return (true);
}
