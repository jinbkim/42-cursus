/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:55:42 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/26 17:59:33 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_path(char *s)
{
	int i;

	i = 0;
	while (is_space(s[i]))
		i++;
	if (s[i] != 'N' && s[i] != 'S' && s[i] != 'W'
		&& s[i] != 'E' && s[i] != 'H')
		return (ERROR);
	i++;
	if (s[i] != 'O' && s[i] != 'E' && s[i] != 'A' && !is_space(s[i]))
		return (ERROR);
	i++;
	while (is_space(s[i]))
		i++;
	if (s[i] != '.' && s[i + 1] != '/')
		return (ERROR);
	while (ft_isprint(s[i]) && !is_space(s[i]) && s[i])
		i++;
	if (!is_space(s[i]) && s[i])
		return (ERROR);
	while (is_space(s[i]))
		i++;
	return (!s[i]);
}

int		check_resol(char *s)
{
	int i;

	i = 0;
	while (is_space(s[i]))
		i++;
	if (!s || s[i] != 'R' || s[i++ + 1] != ' ')
		return (ERROR);
	while (is_space(s[i]))
		i++;
	if (!ft_isdigit(s[i]))
		return (ERROR);
	while (ft_isdigit(s[i]))
		i++;
	if (!is_space(s[i]))
		return (ERROR);
	while (is_space(s[i]))
		i++;
	while (ft_isdigit(s[i]))
		i++;
	while (is_space(s[i]))
		i++;
	if (!is_space(s[i]) && s[i])
		return (ERROR);
	return (SUCCES);
}

int		check_color(char *s, int c, int idx, t_win *win)
{
	int i;

	if (!s || s[idx] != c || !is_space(s[idx + 1]))
		return (ERROR);
	i = idx + 1;
	while (is_space(s[i]))
		i++;
	while (ft_isdigit(s[i]) || s[i] == ',')
		i++;
	while (is_space(s[i]))
		i++;
	if (s[i] != '\0')
		show_error(1, win, ft_strjoin("Error\nwrong line : ", s));
	return (SUCCES);
}

int		check_map(t_win *win, char **map)
{
	int x;
	int y;

	if (!*map || !**map)
		return (ERROR);
	y = -1;
	while (++y < win->map->height)
	{
		if (ft_strlen(map[y]) != (int)win->map->width)
			return (ERROR);
		x = -1;
		while (++x < win->map->width)
		{
			if ((y == 0 && map[y][x] != '1') || (y == win->map->height - 1 &&
				map[y][x] != '1') || (x == 0 && map[y][x] != '1') ||
				(x == win->map->width - 1 && map[y][x] != '1'))
				return (ERROR);
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != '2')
				return (ERROR);
		}
	}
	return (SUCCES);
}
