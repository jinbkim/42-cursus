/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/09/09 12:37:38 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_except(char **cmds)
{
	if (g_except[SYNTAX])
	{
		ft_putstr("-minishell: syntax error near unexpected token `");
		if (g_except[SYNTAX] == '|')
			ft_putstr_newline("|'");
		else if (ft_strchr("<>", g_except[SYNTAX]) != NOTHING)
			ft_putstr_newline("newline'");
	}
	else
	{
		ft_putstr("minishell: ");
		ft_putstr(*cmds);
		ft_putstr_newline(": command not found");
	}
	exit(127);
}

void	exec_cmds(char ***cmds)
{
	int i;

	if (!cmds)
		return ;
	i = -1;
	while (cmds[++i])
	{
		if (g_except[NONE])
			g_except[NONE] = 0;
		else if (pipes(cmds[i]) ||
			redirections(cmds[i]) ||
			builtins(cmds[i], cmds) ||
			excutables(1, 0, cmds[i]))
		{
		}
		else
			do_except(cmds[i]);
	}
}
