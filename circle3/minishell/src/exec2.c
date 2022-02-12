/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/09/07 21:35:40 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_path2(char *cmd, char **env_path)
{
	struct stat	sb;
	char		*new_path;
	int			i;

	i = -1;
	while (env_path[++i])
	{
		env_path[i] = ft_gnljoin(env_path[i], "/");
		new_path = ft_strjoin(env_path[i], cmd);
		if (!stat(new_path, &sb))
		{
			free_2d_arr(env_path);
			return (new_path);
		}
		free_init(&new_path, NULL);
	}
	free_2d_arr(env_path);
	return (0);
}

char	*find_path(char *cmd)
{
	struct stat	sb;
	char		**env_path;
	char		*new_path;
	int			i;

	if (!stat(cmd, &sb))
		return (ft_strdup(cmd));
	env_path = NULL;
	i = -1;
	while (g_envp[++i])
		if (!ft_strncmp(g_envp[i], "PATH=", 5))
			env_path = ft_split(g_envp[i] + 5, ':');
	if (!env_path)
		return (NULL);
	new_path = find_path2(cmd, env_path);
	return (new_path);
}

void	change_cmds(char **cmds)
{
	int i;
	int	j;

	if (!ft_strcmp(cmds[0], "pwd"))
	{
		i = 0;
		while (cmds[++i])
			free(cmds[i]);
		cmds[1] = NULL;
	}
	else if (!ft_strcmp(cmds[0], "echo") && cmds[1] && cmds[2]
		&& !ft_strcmp(cmds[1], "-n") && !ft_strcmp(cmds[2], "-n"))
	{
		i = 3;
		while (!ft_strcmp(cmds[i], "-n"))
			i++;
		j = 1;
		while (++j && cmds[i + j - 2])
			free_init(&cmds[j], ft_strdup(cmds[i + j - 2]));
		i = j;
		while (cmds[j])
			free(cmds[j++]);
		cmds[i] = NULL;
	}
}

int		excutables(int fd_o, int fd_i, char **argv)
{
	pid_t	child;
	int		status;
	char	*path;

	path = find_path(argv[0]);
	child = fork();
	if (argv[0])
		change_cmds(argv);
	if (!child)
	{
		if (fd_o != 1)
			dup2(fd_o, 1);
		if (fd_i != 0)
			dup2(fd_i, 0);
		if (execve(path, argv, g_envp) == -1)
			return (0);
	}
	else
	{
		waitpid(child, &status, 0);
		g_exit_code = status / 256;
		free(path);
	}
	return (1);
}
