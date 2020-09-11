/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:33:09 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/28 12:00:51 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	predict_wall_face(t_ray *ray)
{
	if (ray->sdx < ray->sdy)
	{
		ray->sdx += ray->ddx;
		ray->mapx += ray->step_x;
		if (ray->step_x == 1)
			ray->side = 0;
		else if (ray->step_x == -1)
			ray->side = 1;
	}
	else
	{
		ray->sdy += ray->ddy;
		ray->mapy += ray->step_y;
		if (ray->step_y == 1)
			ray->side = 2;
		else if (ray->step_y == -1)
			ray->side = 3;
	}
}

void	next_sprite(t_sprites *actual, t_sprites *new, t_ray *ray)
{
	while (1)
	{
		if (actual->x == ray->mapx && actual->y == ray->mapy)
		{
			free(new);
			break ;
		}
		if ((actual->x != ray->mapx || actual->y != ray->mapy)
			&& !actual->next)
		{
			actual->next = new;
			break ;
		}
		if (actual->next)
			actual = actual->next;
		else
		{
			free(new);
			break ;
		}
	}
}

void	is_sprite(t_ray *ray, t_win *win)
{
	t_sprites *new;
	t_sprites *actual;
	t_sprites save_top;

	if (!(new = malloc(sizeof(t_sprites))))
		return ;
	new->next = NULL;
	new->x = ray->mapx;
	new->y = ray->mapy;
	actual = win->spr_screen;
	save_top = *actual;
	if (actual->x == -1 && actual->y == -1)
	{
		actual->x = ray->mapx;
		actual->y = ray->mapy;
	}
	else
		next_sprite(actual, new, ray);
	actual = &save_top;
}

void	perp_and_height(t_ray *ray, t_player *player, t_win *win)
{
	if (ray->side == 0 || ray->side == 1)
		ray->pwd = (ray->mapx - player->posx + (1 - ray->step_x) / 2)
		/ ray->rdx;
	else
		ray->pwd = (ray->mapy - player->posy + (1 - ray->step_y) / 2)
		/ ray->rdy;
	ray->line_height = (int)(win->height / ray->pwd);
	ray->draw_start = (-ray->line_height / 2 + ((win->height / 2)
		* win->player->cam_height));
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height / 2 + ((win->height / 2)
		* win->player->cam_height));
	if (ray->draw_end >= win->height)
		ray->draw_end = win->height - 1;
}
