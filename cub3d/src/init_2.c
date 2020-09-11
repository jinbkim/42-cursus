/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:37:25 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/28 12:08:33 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			init_game_player(t_win *win)
{
	if (!(win->player = malloc(sizeof(t_player))))
		return (ERROR);
	ft_bzero(win->player, sizeof(t_player));
	win->player->posx = -20.0;
	win->player->posy = -20.0;
	win->player->speed = 0.10;
	win->player->dir_x = -20.0;
	win->player->dir_y = -20.0;
	win->player->plane_x = -20.0;
	win->player->plane_y = -20.0;
	win->player->rot_speed = 0.10;
	win->player->cam_height = 1.0;
	win->player->health = 20;
	return (SUCCES);
}

t_image		*new_image(t_win *win, int width, int height)
{
	t_image *img;

	if (!(img = malloc(sizeof(t_image))))
		return (NULL);
	ft_bzero(img, sizeof(t_image));
	if (!(img->img_ptr = mlx_new_image(win->mlx_ptr, width, height)))
		return (NULL);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
		&img->size_line, &img->endian);
	img->width = width;
	img->height = height;
	return (img);
}

int			init_game_window_ptwo(t_win *win)
{
	char	*map;

	win->save = 0;
	if (!(map = treat_desc(win->map->map_name, win)))
	{
		free(map);
		return (ERROR);
	}
	win->map->map = read_map2(map, win);
	if (!(win->win_ptr = mlx_new_window(win->mlx_ptr,
		win->width, win->height, "cub3d")))
		return (ERROR);
	if (!(win->img = new_image(win, win->width, win->height)))
		return (ERROR);
	return (SUCCES);
}
