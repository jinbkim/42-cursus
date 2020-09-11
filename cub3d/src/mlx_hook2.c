/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:58:53 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/28 11:11:08 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_win *win)
{
	if (win->map->map[(int)win->player->posy]
		[(int)(win->player->posx + win->player->dir_x
		* win->player->speed * 2)] == '0')
		win->player->posx += win->player->dir_x
		* win->player->speed;
	if (win->map->map[(int)(win->player->posy
		+ win->player->dir_y * win->player->speed * 2)]
		[(int)win->player->posx] == '0')
		win->player->posy += win->player->dir_y
		* win->player->speed;
}

void	move_backward(t_win *win)
{
	if (win->map->map[(int)win->player->posy]
		[(int)(win->player->posx - win->player->dir_x
		* win->player->speed * 2)] == '0')
		win->player->posx -= win->player->dir_x
		* win->player->speed;
	if (win->map->map[(int)(win->player->posy
		- win->player->dir_y * win->player->speed * 2)]
		[(int)win->player->posx] == '0')
		win->player->posy -= win->player->dir_y
		* win->player->speed;
}

void	move_left(t_win *win)
{
	if (win->map->map[(int)win->player->posy]
		[(int)(win->player->posx - win->player->plane_x
		* win->player->speed * 2)] == '0')
		win->player->posx -= win->player->plane_x
		* win->player->speed;
	if (win->map->map[(int)(win->player->posy
		- win->player->plane_y * win->player->speed * 2)]
		[(int)win->player->posx] == '0')
		win->player->posy -= win->player->plane_y
		* win->player->speed;
}

void	move_right(t_win *win)
{
	if (win->map->map[(int)win->player->posy]
		[(int)(win->player->posx + win->player->plane_x
		* win->player->speed * 2)] == '0')
		win->player->posx += win->player->plane_x
		* win->player->speed;
	if (win->map->map[(int)(win->player->posy
		+ win->player->plane_y * win->player->speed * 2)]
		[(int)win->player->posx] == '0')
		win->player->posy += win->player->plane_y
		* win->player->speed;
}

int		key_manager(t_win *win)
{
	if (win->keybuffer->toward == 1)
		move_forward(win);
	if (win->keybuffer->backward == 1)
		move_backward(win);
	if (win->keybuffer->left == 1)
		move_left(win);
	if (win->keybuffer->right == 1)
		move_right(win);
	if (win->keybuffer->turn_left == 1)
		turn_left(win);
	if (win->keybuffer->turn_right == 1)
		turn_right(win);
	return (SUCCES);
}
