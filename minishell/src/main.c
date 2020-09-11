/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/09/08 11:59:01 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_init(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	ft_memset(g_except, 0, sizeof(int) * EX_END);
	ft_memset(g_flag, 0, sizeof(int) * F_END);
	g_envp = copy_2d_arr(envp, MAX);
	catch_signals();
}

void	exit_minishell(char ***cmds)
{
	ft_putstr_newline("exit");
	if (cmds)
	{
		if (cmds[0][1])
		{
			ft_putstr("-minishell: exit: ");
			ft_putstr(cmds[0][1]);
			ft_putstr_newline(": numeric argument required");
		}
		free_3d_arr(cmds);
	}
	free_2d_arr(g_envp);
	exit(0);
}

int		main(int argc, char **argv, char **envp)
{
	char	***cmds;
	char	*line;

	minishell_init(argc, argv, envp);
	while (1)
	{
		if (g_flag[CTRL_BS])
			g_flag[CTRL_BS] = 0;
		else
			ft_putstr("minishell$ ");
		while (!(get_next_line(0, &line)))
		{
			if (!g_flag[CTRL_D] && !line[0])
				exit_minishell(0);
			g_flag[CTRL_D] = 1;
		}
		ft_memset(g_flag, 0, sizeof(int) * F_END);
		cmds = parsing_cmds(line);
		exec_cmds(cmds);
		free_3d_arr(cmds);
	}
	return (0);
}
