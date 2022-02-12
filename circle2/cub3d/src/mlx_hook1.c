/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:55:30 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/26 17:59:10 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		event_key_pressed(int key, void *param)
{
	t_win	*win;

	win = (t_win *)param;
	if (key == ESC)
		show_error(0, win, "");
	else if (key == TOWARD && win->keybuffer->toward == 0)
		win->keybuffer->toward = 1;
	else if (key == BACKWARD && win->keybuffer->backward == 0)
		win->keybuffer->backward = 1;
	else if (key == LEFT && win->keybuffer->left == 0)
		win->keybuffer->left = 1;
	else if (key == RIGHT && win->keybuffer->right == 0)
		win->keybuffer->right = 1;
	else if (key == CAM_LEFT && win->keybuffer->turn_left == 0)
		win->keybuffer->turn_left = 1;
	else if (key == CAM_RIGHT && win->keybuffer->turn_right == 0)
		win->keybuffer->turn_right = 1;
	return (SUCCES);
}

int		event_key_released(int key, void *param)
{
	t_win	*win;

	win = (t_win *)param;
	if (key == TOWARD && win->keybuffer->toward == 1)
		win->keybuffer->toward = 0;
	else if (key == BACKWARD && win->keybuffer->backward == 1)
		win->keybuffer->backward = 0;
	else if (key == LEFT && win->keybuffer->left == 1)
		win->keybuffer->left = 0;
	else if (key == RIGHT && win->keybuffer->right == 1)
		win->keybuffer->right = 0;
	else if (key == CAM_LEFT && win->keybuffer->turn_left == 1)
		win->keybuffer->turn_left = 0;
	else if (key == CAM_RIGHT && win->keybuffer->turn_right == 1)
		win->keybuffer->turn_right = 0;
	return (SUCCES);
}

int		event_destroy_window(void *param)
{
	t_win *win;

	win = (t_win *)param;
	show_error(0, win, "");
	return (SUCCES);
}

void	draw(t_win *win)
{
	if (!(raycasting(win)))
		show_error(0, win, "");
}

int		loop_manager(void *param)
{
	t_win *win;

	win = (t_win *)param;
	draw(win);
	key_manager(win);
	return (SUCCES);
}
