/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:13:45 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/28 11:29:15 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_color(char *line, int *i)
{
	int color;

	color = ft_atoi(&line[*i]);
	if (color < 0 || color > 255)
		return (-1);
	while (ft_isdigit(line[*i]))
		*i += 1;
	*i += 1;
	return (color);
}

int		get_rgb(int r, int g, int b)
{
	int rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}

int		read_color(char *line, int c, int idx, t_win *win)
{
	int rgb;
	int r;
	int g;
	int b;
	int i;

	rgb = 0;
	if (!check_color(line, c, idx, win))
		return (ERROR);
	i = idx + 1;
	while (is_space(line[i]))
		i++;
	if ((r = get_color(line, &i)) == -1 ||
		(g = get_color(line, &i)) == -1 ||
		(b = get_color(line, &i)) == -1)
		return (ERROR);
	rgb = get_rgb(r, g, b);
	if (c == 'F')
		win->col_flo = rgb;
	else
		win->col_ceil = rgb;
	return (SUCCES);
}

void	set_start_came(t_win *win, double dirx, double planex, double planey)
{
	win->player->dir_x = dirx;
	win->player->plane_x = planex;
	win->player->plane_y = planey;
}

int		free_return(void *p, int ret)
{
	free(p);
	return (ret);
}
