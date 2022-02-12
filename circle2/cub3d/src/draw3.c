/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:35:48 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/27 18:16:50 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_on_img(t_line *line, t_image *texture, t_win *win, t_ray *ray)
{
	int d;

	d = line->y * texture->size_line - (win->height
		* win->player->cam_height) * texture->size_line
		/ 2 + ray->line_height * texture->size_line / 2;
	line->tex_y = ((d * texture->height) / ray->line_height)
		/ texture->size_line;
	win->img->data[line->y * win->img->size_line + line->x
					* win->img->bpp / 8] = texture->data[line->tex_y
					* texture->size_line + line->tex_x * (texture->bpp / 8)];
	win->img->data[line->y * win->img->size_line + line->x
					* win->img->bpp / 8 + 1] = texture->data[line->tex_y
					* texture->size_line + line->tex_x * (texture->bpp / 8)
					+ 1];
	win->img->data[line->y * win->img->size_line + line->x
					* win->img->bpp / 8 + 2] = texture->data[line->tex_y
					* texture->size_line + line->tex_x * (texture->bpp / 8)
					+ 2];
}

void	ver_line_tex_img(t_line *l, t_win *win, t_image *tex, t_ray *ray)
{
	int y_max;

	if (l->y0 < l->y1)
	{
		l->y = l->y0;
		y_max = l->y1;
	}
	else
	{
		l->y = l->y1;
		y_max = l->y0;
	}
	if (l->y >= 0)
	{
		while (l->y < y_max)
		{
			texture_on_img(l, tex, win, ray);
			l->y++;
		}
	}
}

void	side_draw(t_ray *ray, t_win *win, t_line *line, double wall_x)
{
	t_image	*img;
	int		tex_x;

	img = win->tex[3];
	if (ray->side == 1)
		img = win->tex[2];
	if (ray->side == 2)
		img = win->tex[1];
	if (ray->side == 3)
		img = win->tex[0];
	tex_x = (int)(wall_x * (double)img->width);
	if ((ray->side == 0 || ray->side == 1) && ray->rdx > 0)
		tex_x = img->width - tex_x - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->rdy < 0)
		tex_x = img->width - tex_x - 1;
	line->y0 = ray->draw_end;
	line->y1 = ray->draw_start;
	line->tex_x = tex_x;
	ver_line_tex_img(line, win, img, ray);
}

void	ver_line_color_image(t_line *line, t_win *win, int color)
{
	int y;
	int y_max;

	if (line->y0 < line->y1)
	{
		y = line->y0;
		y_max = line->y1;
	}
	else
	{
		y = line->y1;
		y_max = line->y0;
	}
	if (y >= 0)
	{
		while (y < y_max)
		{
			pixel_put_to_image(color, line->x, y, win->img);
			y++;
		}
	}
}

void	texturisation(t_ray *ray, t_win *win)
{
	t_line	*line;
	double	wall_x;

	if (!(line = malloc(sizeof(t_line))))
		show_error(1, win, "Error\nwrong\n");
	ft_bzero(line, sizeof(t_line));
	line->x = ray->pix;
	if (ray->side == 0 || ray->side == 1)
		wall_x = win->player->posy + ray->pwd * ray->rdy;
	else
		wall_x = win->player->posx + ray->pwd * ray->rdx;
	wall_x -= floor(wall_x);
	if (win->map->map[ray->mapy][ray->mapx] == '1')
		side_draw(ray, win, line, wall_x);
	line->y0 = 0;
	line->y1 = ray->draw_start;
	ver_line_color_image(line, win, win->col_ceil);
	line->y0 = win->height;
	line->y1 = ray->draw_end;
	ver_line_color_image(line, win, win->col_flo);
	free(line);
}
