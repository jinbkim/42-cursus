/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:31:10 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/28 12:15:45 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_values(t_ray *ray, t_player *player, t_win *win)
{
	ray->camera_x = (2 * ray->pix) / (double)win->width - 1;
	ray->rdx = player->dir_x + player->plane_x * ray->camera_x;
	ray->rdy = player->dir_y + player->plane_y * ray->camera_x;
	ray->mapx = (int)player->posx;
	ray->mapy = (int)player->posy;
	ray->ddx = fabs(1 / ray->rdx);
	ray->ddy = fabs(1 / ray->rdy);
	ray->hit = 0;
}

void	next_step(t_ray *ray, t_player *player)
{
	if (ray->rdx < 0)
	{
		ray->step_x = -1;
		ray->sdx = (player->posx - ray->mapx) * ray->ddx;
	}
	else
	{
		ray->step_x = 1;
		ray->sdx = (ray->mapx + 1.0 - player->posx) * ray->ddx;
	}
	if (ray->rdy < 0)
	{
		ray->step_y = -1;
		ray->sdy = (player->posy - ray->mapy) * ray->ddy;
	}
	else
	{
		ray->step_y = 1;
		ray->sdy = (ray->mapy + 1.0 - player->posy) * ray->ddy;
	}
}

void	hit(t_ray *ray, t_win *win)
{
	while (ray->hit == 0)
	{
		predict_wall_face(ray);
		if (win->map->map[ray->mapy][ray->mapx] > '0'
			&& win->map->map[ray->mapy][ray->mapx] != '2')
			ray->hit = 1;
		else if (win->map->map[ray->mapy][ray->mapx] == '2')
			is_sprite(ray, win);
	}
}

void	do_raycasting(t_win *win, t_ray *ray)
{
	t_player	*player;

	player = win->player;
	init_values(ray, player, win);
	next_step(ray, player);
	hit(ray, win);
	perp_and_height(ray, player, win);
	ray->z_buffer[ray->pix] = ray->pwd;
	texturisation(ray, win);
	ray->pix++;
}

int		raycasting(t_win *win)
{
	t_ray		*ray;

	if (!(ray = malloc(sizeof(t_ray))))
		return (ERROR);
	ft_bzero(ray, sizeof(t_ray));
	if (!(ray->z_buffer = malloc(sizeof(double) * win->width)))
		return (ERROR);
	ft_bzero(ray->z_buffer, sizeof(double) * win->width);
	while (ray->pix < win->width)
		do_raycasting(win, ray);
	if (!draw_sprite(ray, win))
		return (ERROR);
	if (win->save == 1)
	{
		win->save = 0;
		create_bitmap(win->img, "cub3D");
		show_error(0, win, "");
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
		win->img->img_ptr, 0, 0);
	free(ray->z_buffer);
	free(ray);
	return (SUCCES);
}
