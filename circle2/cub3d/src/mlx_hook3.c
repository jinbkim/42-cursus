/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 18:00:05 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/26 17:59:04 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_left(t_win *win)
{
	double olddirx;
	double oldplanex;

	olddirx = win->player->dir_x;
	oldplanex = win->player->plane_x;
	win->player->dir_x = win->player->dir_x
			* cos(-win->player->rot_speed) - win->player->dir_y
			* sin(-win->player->rot_speed);
	win->player->dir_y = olddirx * sin(-win->player->rot_speed)
			+ win->player->dir_y * cos(-win->player->rot_speed);
	win->player->plane_x = win->player->plane_x
			* cos(-win->player->rot_speed) - win->player->plane_y
			* sin(-win->player->rot_speed);
	win->player->plane_y = oldplanex
			* sin(-win->player->rot_speed) + win->player->plane_y
			* cos(-win->player->rot_speed);
}

void	turn_right(t_win *win)
{
	double olddirx;
	double oldplanex;

	olddirx = win->player->dir_x;
	oldplanex = win->player->plane_x;
	win->player->dir_x = win->player->dir_x
			* cos(win->player->rot_speed) - win->player->dir_y
			* sin(win->player->rot_speed);
	win->player->dir_y = olddirx * sin(win->player->rot_speed)
			+ win->player->dir_y * cos(win->player->rot_speed);
	win->player->plane_x = win->player->plane_x
			* cos(win->player->rot_speed) - win->player->plane_y
			* sin(win->player->rot_speed);
	win->player->plane_y = oldplanex
			* sin(win->player->rot_speed) + win->player->plane_y
			* cos(win->player->rot_speed);
}
