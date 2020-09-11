/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/09/07 20:38:49 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_process(char **cmds, char *path, int *fd)
{
	int	i;

	dup2(fd[1], 1);
	if (fd[0] != 0)
		close(fd[0]);
	if (fd[1] != 1)
		close(fd[1]);
	i = -1;
	while (cmds[++i])
	{
		if (ft_strchr(cmds[i], '<') != -1 || ft_strchr(cmds[i], '>') != -1)
		{
			redirections(cmds);
			return ;
		}
	}
	execve(path, cmds, g_envp);
	exit(0);
}

void	parent_process(char ***cmds, char **path, int *fd, int i)
{
	int		fd2[2];

	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
	fd2[0] = 0;
	fd2[1] = 1;
	if (cmds[i + 1] != 0)
		pipe(fd2);
	pipes_exec(cmds, path, fd2, i);
}

void	pipes_exec(char ***cmds, char **path, int *fd, int i)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (!pid)
		child_process(cmds[i], path[i], fd);
	else
	{
		waitpid(pid, &status, 0);
		g_exit_code = status / 256;
		if (cmds[i + 1])
			parent_process(cmds, path, fd, i + 1);
	}
}
