/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:31:02 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/27 17:02:15 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_win	*init_game_window_pone(void)
{
	t_win *win;

	if (!(win = malloc(sizeof(t_win))))
		exit(1);
	ft_bzero(win, sizeof(t_win));
	if (!(win->mlx_ptr = mlx_init()))
		return (ERROR);
	win->map_start = 0;
	win->m_start_space = 0;
	return (win);
}

int		init_game_tex(t_win *win, int n)
{
	int cnt;

	if (!(win->tex = malloc(sizeof(t_image *) * (n + 1))))
		return (ERROR);
	cnt = -1;
	while (++cnt < n)
	{
		if (!(win->tex[cnt] = malloc(sizeof(t_image))))
			return (ERROR);
		ft_bzero(win->tex[cnt], sizeof(t_image));
	}
	return (SUCCES);
}

int		init_game_sprite(t_win *win)
{
	if (!(win->sprite = malloc(sizeof(t_image))))
		return (ERROR);
	ft_bzero(win->sprite, sizeof(t_image));
	if (!(win->spr_screen = malloc(sizeof(t_list))))
		return (ERROR);
	ft_bzero(win->spr_screen, sizeof(t_list));
	win->spr_screen->x = -1;
	win->spr_screen->y = -1;
	return (SUCCES);
}

int		init_game_map(t_win *win, char *map_name)
{
	if (!(win->map = malloc(sizeof(t_map))))
		return (ERROR);
	ft_bzero(win->map, sizeof(t_map));
	win->map->map_name = map_name;
	win->map->height = 0;
	win->map->width = 0;
	return (SUCCES);
}

int		init_game_keybuffer(t_win *win)
{
	if (!(win->keybuffer = malloc(sizeof(t_keybuffer))))
		return (ERROR);
	ft_bzero(win->keybuffer, sizeof(t_keybuffer));
	win->keybuffer->toward = 0;
	win->keybuffer->backward = 0;
	win->keybuffer->left = 0;
	win->keybuffer->right = 0;
	win->keybuffer->turn_left = 0;
	win->keybuffer->turn_right = 0;
	win->keybuffer->cam_up = 0;
	win->keybuffer->cam_down = 0;
	return (SUCCES);
}
