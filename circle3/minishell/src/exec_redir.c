/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/09/07 20:37:01 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_in(char **cmd, char **file)
{
	int fd;
	int	i;

	i = -1;
	while (0 <= ++i)
	{
		if ((fd = open(file[i], O_RDONLY)) == -1)
		{
			ft_putstr("-minishell: ");
			ft_putstr(file[i]);
			ft_putstr_newline(": No such file or directory");
			return ;
		}
		else if (!file[i + 1])
			break ;
		else
			close(fd);
	}
	excutables(1, fd, cmd);
	close(fd);
}

void	redir_out(char **cmd, char **file, char overwrite)
{
	int	fd;
	int	i;

	i = -1;
	while (0 <= ++i)
	{
		if (overwrite == 'y')
			fd = open(file[i], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
		else
			fd = open(file[i], O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
		if (!file[i + 1])
			break ;
		else
			close(fd);
	}
	excutables(fd, 0, cmd);
	close(fd);
}

void	redirections2(char **cmd, char **cmd_cpy, char *redi)
{
	char	**file;
	int		i;
	int		j;

	file = (char **)malloc(sizeof(char *) * MAX);
	i = -1;
	j = -1;
	while (cmd[++i])
		if (!ft_strcmp(cmd[i], "<") || !ft_strcmp(cmd[i], ">")
			|| !ft_strcmp(cmd[i], ">>"))
			file[++j] = ft_strdup(cmd[i + 1]);
	file[++j] = NULL;
	if (!ft_strcmp(redi, "<"))
		redir_in(cmd_cpy, file);
	else if (!ft_strcmp(redi, ">"))
		redir_out(cmd_cpy, file, 'y');
	else if (!ft_strcmp(redi, ">>"))
		redir_out(cmd_cpy, file, 'n');
	free_2d_arr(file);
}

int		redirections(char **cmd)
{
	char	**cmd_cpy;
	char	*redi;
	int		i;

	i = -1;
	while (cmd[++i])
	{
		if (!ft_strcmp(cmd[i], "<") || !ft_strcmp(cmd[i], ">")
			|| !ft_strcmp(cmd[i], ">>"))
		{
			cmd_cpy = copy_2d_arr(cmd, i);
			redi = ft_strdup(cmd[i]);
			break ;
		}
	}
	if (!cmd[i])
		return (0);
	redirections2(cmd, cmd_cpy, redi);
	free(redi);
	free_2d_arr(cmd_cpy);
	return (1);
}
