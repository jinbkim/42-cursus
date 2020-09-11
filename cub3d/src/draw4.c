/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:40:11 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/27 15:03:48 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		pixel_put_to_image(int color, int x, int y, t_image *img)
{
	unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	src = (unsigned char *)&color;
	r = src[0];
	g = src[1];
	b = src[2];
	img->data[y * img->size_line + x * img->bpp / 8] = r;
	img->data[y * img->size_line + x * img->bpp / 8 + 1] = g;
	img->data[y * img->size_line + x * img->bpp / 8 + 2] = b;
}

t_sprite	*list_to_tab(t_win *win)
{
	t_sprite	*rtn;
	t_sprites	*save_top;
	int			count;

	save_top = win->spr_screen;
	count = -1;
	if (!(rtn = malloc(sizeof(t_sprite)
		* ft_lstsize((t_list *)win->spr_screen))))
		return (ERROR);
	ft_bzero(rtn, sizeof(t_sprite)
		* ft_lstsize((t_list *)win->spr_screen));
	while (++count > -1)
	{
		if (win->spr_screen)
		{
			rtn[count].x = win->spr_screen->x;
			rtn[count].y = win->spr_screen->y;
		}
		if (win->spr_screen->next)
			win->spr_screen = win->spr_screen->next;
		else
			break ;
	}
	win->spr_screen = save_top;
	return (rtn);
}

void		sort_sprite(t_win *win, t_sprite *sprites, int nbr_sprites)
{
	int			i;
	double		dist_one;
	double		dist_two;
	t_sprite	tmp;

	i = 0;
	while (i < nbr_sprites && i + 1 != nbr_sprites)
	{
		dist_one = ((win->player->posx - sprites[i].x)
		* (win->player->posx - sprites[i].x) + (win->player->posy
		- sprites[i].y) * (win->player->posy - sprites[i].y));
		dist_two = ((win->player->posx - sprites[i + 1].x)
		* (win->player->posx - sprites[i + 1].x)
		+ (win->player->posy - sprites[i + 1].y)
		* (win->player->posy - sprites[i + 1].y));
		if (dist_one < dist_two)
		{
			tmp = sprites[i];
			sprites[i] = sprites[i + 1];
			sprites[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int			draw_sprite(t_ray *ray, t_win *win)
{
	t_draw_sprite *ds;

	if (!(ds = malloc(sizeof(t_draw_sprite))))
		return (ERROR);
	ft_bzero(ds, sizeof(t_draw_sprite));
	ds->i = 0;
	ds->sprites = list_to_tab(win);
	sort_sprite(win, ds->sprites,
		ft_lstsize((t_list *)win->spr_screen));
	while (ds->i < ft_lstsize((t_list *)win->spr_screen))
	{
		make_sprite(ds, win, ray);
		ds->i++;
	}
	free(ds->sprites);
	free(ds);
	return (SUCCES);
}
