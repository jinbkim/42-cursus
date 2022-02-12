/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:43:38 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/26 17:59:21 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calcul_values(t_draw_sprite *ds, t_win *win)
{
	ds->inv_det = 1.0 / (win->player->plane_x * win->player->dir_y
		- win->player->dir_x * win->player->plane_y);
	ds->trans_x = ds->inv_det * (win->player->dir_y * ds->sprite_x
		- win->player->dir_x * ds->sprite_y);
	ds->trans_y = ds->inv_det * (-win->player->plane_y * ds->sprite_x
		+ win->player->plane_x * ds->sprite_y);
	ds->spr_sc_x = (int)((win->width / 2) * (1 + ds->trans_x
		/ ds->trans_y));
	ds->spr_h = abs((int)(win->height / ds->trans_y));
	ds->draw_start_y = -ds->spr_h / 2 + ((win->height / 2)
		* win->player->cam_height);
	if (ds->draw_start_y < 0)
		ds->draw_start_y = 0;
	ds->draw_end_y = ds->spr_h / 2 + ((win->height / 2)
		* win->player->cam_height);
	if (ds->draw_end_y >= win->height)
		ds->draw_end_y = win->height - 1;
	ds->spr_w = abs((int)(win->height / ds->trans_y));
	ds->draw_start_x = -ds->spr_w / 2 + ds->spr_sc_x;
	if (ds->draw_start_x < 0)
		ds->draw_start_x = 0;
	ds->draw_end_x = ds->spr_w / 2 + ds->spr_sc_x;
	if (ds->draw_end_x >= win->width)
		ds->draw_end_x = win->width - 1;
	ds->stripe = ds->draw_start_x;
}

void	pix_on_sprite_image(t_draw_sprite *ds, t_win *win)
{
	ds->d = ds->y * win->sprite->size_line - (win->height
		* win->player->cam_height)
		* (win->sprite->size_line / 2) + ds->spr_h
		* win->sprite->size_line / 2;
	ds->tex_y = ((ds->d * win->sprite->height) / ds->spr_h)
		/ win->sprite->size_line;
	ds->totcolor = win->sprite->data[ds->tex_y
		* win->sprite->size_line + ds->tex_x
		* win->sprite->bpp / 8]
		+ win->sprite->data[ds->tex_y
		* win->sprite->size_line + ds->tex_x
		* win->sprite->bpp / 8 + 1]
		+ win->sprite->data[ds->tex_y
		* win->sprite->size_line + ds->tex_x
		* win->sprite->bpp / 8 + 2];
}

void	is_black(t_draw_sprite *ds, t_win *win)
{
	win->img->data[ds->y * win->img->size_line
		+ ds->stripe * win->img->bpp / 8] =
		win->sprite->data[ds->tex_y
		* win->sprite->size_line + ds->tex_x
		* win->sprite->bpp / 8];
	win->img->data[ds->y * win->img->size_line
		+ ds->stripe * win->img->bpp / 8 + 1] =
		win->sprite->data[ds->tex_y
		* win->sprite->size_line + ds->tex_x
		* win->sprite->bpp / 8 + 1];
	win->img->data[ds->y * win->img->size_line
		+ ds->stripe * win->img->bpp / 8 + 2] =
		win->sprite->data[ds->tex_y
		* win->sprite->size_line + ds->tex_x
		* win->sprite->bpp / 8 + 2];
}

void	make_sprite(t_draw_sprite *ds, t_win *win, t_ray *ray)
{
	ds->sprite_x = ds->sprites[ds->i].x - (win->player->posx - 0.5);
	ds->sprite_y = ds->sprites[ds->i].y - (win->player->posy - 0.5);
	calcul_values(ds, win);
	while (ds->stripe < ds->draw_end_x)
	{
		ds->tex_x = (int)(win->sprite->size_line * (ds->stripe
		- (-ds->spr_w / 2 + ds->spr_sc_x))
			* win->sprite->width / ds->spr_w)
			/ win->sprite->size_line;
		if (ds->trans_y > 0 && ds->stripe > 0 && ds->stripe
			< win->width && ds->trans_y < ray->z_buffer[ds->stripe])
		{
			ds->y = ds->draw_start_y;
			while (ds->y < ds->draw_end_y)
			{
				pix_on_sprite_image(ds, win);
				if (ds->totcolor != 0)
					is_black(ds, win);
				ds->y++;
			}
		}
		ds->stripe++;
	}
}
