/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/09/07 14:15:24 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_home(void)
{
	char	*home;
	int		i;

	home = NULL;
	i = -1;
	while (g_envp[++i])
	{
		if (!ft_strncmp(g_envp[i], "HOME=", 5))
		{
			home = ft_strdup(g_envp[i] + 5);
			break ;
		}
	}
	return (home);
}

void	do_cd(char **argv)
{
	char	*err_msg;
	char	*home;
	int		i;

	if (argv[2])
	{
		i = 1;
		while (argv[++i])
			free(argv[i]);
		argv[2] = NULL;
	}
	if (!argv[1])
	{
		home = find_home();
		chdir(home);
		free(home);
	}
	else if (chdir(argv[1]) == -1)
	{
		err_msg = strerror(errno);
		ft_putstr("-minishell: cd: ");
		ft_putstr(argv[1]);
		ft_putstr(": ");
		ft_putstr_newline(err_msg);
	}
}

void	do_env(char **argv)
{
	int i;

	i = -1;
	if (argv[1])
	{
		ft_putstr("env: ");
		ft_putstr(argv[1]);
		ft_putstr_newline(": No such file or directory");
		return ;
	}
	while (g_envp[++i] && g_envp[i][0])
		ft_putstr_newline(g_envp[i]);
}

int		builtins(char **argv, char ***cmds)
{
	if (!argv[0])
		return (0);
	if (!ft_strcmp(argv[0], "echo") || (!ft_strcmp(argv[0], "pwd")))
		excutables(1, 0, argv);
	else if (!ft_strcmp(argv[0], "cd"))
		do_cd(argv);
	else if (!ft_strcmp(argv[0], "exit"))
		exit_minishell(cmds);
	else if (!ft_strcmp(argv[0], "env"))
		do_env(argv);
	else if (!ft_strcmp(argv[0], "export"))
		do_export(argv);
	else if (!ft_strcmp(argv[0], "unset"))
		do_unset(argv);
	else
		return (0);
	return (1);
}
