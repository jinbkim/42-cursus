/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:19:20 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/27 15:39:05 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map_size(char *str, t_win *win)
{
	int i;
	int j;
	int	width;
	int	height;

	i = -1;
	width = 0;
	while (str[++i] != '\n')
		if (!is_space(str[i]))
			width++;
	win->map->width = width;
	j = 0;
	height = 0;
	while (str[j])
	{
		if (str[j] == '\n')
			height++;
		j++;
		if (str[j] == '\0' && (j > 0 && str[j - 1] != '\n'))
			height++;
	}
	win->map->height = height;
}

char	**malloc_map(t_win *win)
{
	int		i;
	char	**map;

	if (!(map = (char **)malloc(sizeof(char *) * win->map->height)))
		show_error(1, win, "Error\nwrong map malloc");
	ft_bzero(map, sizeof(char *) * win->map->height);
	i = -1;
	while (++i < win->map->height)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * win->map->width + 1)))
			show_error(1, win, "Error\nwrong map malloc");
		ft_bzero(map[i], sizeof(char) * win->map->width);
	}
	return (map);
}

void	set_start_pos(t_win *win, char dir, int x, int y)
{
	if (dir == 'E')
	{
		win->player->dir_y = 0.0;
		set_start_came(win, 1.0, 0.0, 0.66);
	}
	else if (dir == 'W')
	{
		win->player->dir_y = 0.0;
		set_start_came(win, -1.0, 0.0, -0.66);
	}
	else if (dir == 'N')
	{
		win->player->dir_y = -1.0;
		set_start_came(win, 0.0, 0.66, 0.0);
	}
	else if (dir == 'S')
	{
		win->player->dir_y = 1.0;
		set_start_came(win, 0.0, -0.66, 0.0);
	}
	win->player->posx = (double)(x - 1) + 0.5;
	win->player->posy = (double)y + 0.5;
}

char	**init_map(char *s, char **map, t_win *win)
{
	int x;
	int y;
	int i;

	y = -1;
	i = -1;
	while (++y < win->map->height)
	{
		x = 0;
		while (s[++i] && s[i] != '\n')
		{
			if (!is_space(s[i]))
				map[y][x++] = s[i];
			if (s[i] == 'N' || s[i] == 'S' || s[i] == 'W' || s[i] == 'E')
			{
				set_start_pos(win, s[i], x, y);
				map[y][x - 1] = '0';
			}
		}
		map[y][x] = '\0';
	}
	return (map);
}

char	**read_map2(char *str, t_win *win)
{
	char	**map;

	get_map_size(str, win);
	map = malloc_map(win);
	map = init_map(str, map, win);
	if (!check_map(win, map))
		show_error(1, win, "Error\nwrong map format");
	if (win->player->posx == -20.0 || win->player->posy == -20.0 ||
		win->player->dir_x == -20.0 || win->player->dir_y == -20.0)
		show_error(1, win, "player pos or dir set plz");
	free(str);
	return (map);
}
