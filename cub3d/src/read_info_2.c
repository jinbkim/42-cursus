/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:04:44 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/28 11:53:53 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		path_open(const char *path)
{
	int fd;
	int len;

	len = ft_strlen(path);
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		close(fd);
		return (ERROR);
	}
	if (path[len - 1] != 'm' || path[len - 2] != 'p'
		|| path[len - 3] != 'x' || path[len - 4] != '.')
		return (ERROR);
	return (SUCCES);
}

int		set_texture(t_win *win, char *path, int idx, t_w_front *wf)
{
	free(wf);
	if (!(win->tex[idx]->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr,
		(char *)path, &win->tex[idx]->width, &win->tex[idx]->height)))
	{
		free(path);
		return (ERROR);
	}
	win->tex[idx]->data = mlx_get_data_addr(win->tex[idx]->img_ptr,
	&win->tex[idx]->bpp, &win->tex[idx]->size_line, &win->tex[idx]->endian);
	free(path);
	return (SUCCES);
}

int		stock_sprite(char *path, t_win *win, t_w_front *wf)
{
	free(wf);
	if (!(win->sprite->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr,
		path, &win->sprite->width, &win->sprite->height)))
	{
		free(path);
		return (ERROR);
	}
	win->sprite->data = mlx_get_data_addr(win->sprite->img_ptr,
		&win->sprite->bpp, &win->sprite->size_line, &win->sprite->endian);
	free(path);
	return (SUCCES);
}

int		is_map(char *l, char **map, int i, int ret)
{
	char	*save_map;

	if (l[i] == '1' || l[i] == '2' || l[i] == '0' || l[i] == 'N'
		|| (l[i] == 'S') || (l[i] == 'W') || (l[i] == 'E'))
	{
		save_map = *map;
		*map = ft_strjoin(*map, l);
		free(save_map);
		if (ret != 0 && l[i])
		{
			save_map = *map;
			*map = ft_strjoin(*map, "\n");
			free(save_map);
		}
		return (SUCCES);
	}
	return (ERROR);
}

int		is_other(char *line, int idx, t_win *win)
{
	if (line[idx])
	{
		if (line[idx] != '\0' && line[idx] != '\n')
			show_error(1, win, ft_strjoin("Error\nwrong line : ", line));
	}
	else if (line[idx] == '\0' && win->map_start == 1)
		win->m_start_space = 1;
	return (SUCCES);
}
