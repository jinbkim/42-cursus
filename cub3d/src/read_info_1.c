/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:44:56 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/28 12:11:29 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		read_resol(char *line, t_win *win, t_w_front *wf)
{
	int i;

	free(wf);
	if (!check_resol(line))
		show_error(1, win, ft_strjoin("Error\nwrong line : ", line));
	i = 0;
	while (is_space(line[i]))
		i++;
	i += 1;
	while (is_space(line[i]))
		i++;
	win->width = char_to_deci(line, i);
	if (win->width > 2048)
		win->width = 2048;
	while (ft_isdigit(line[i]))
		i++;
	while (is_space(line[i]))
		i++;
	win->height = char_to_deci(line, i);
	if (win->height > 1108)
		win->height = 1108;
	return (SUCCES);
}

int		read_path(char *line, t_w_front *wf, int idx, t_win *win)
{
	char	*path;
	int		i;

	if (!check_path(line))
		show_error(1, win, ft_strjoin("Error\nwrong line : ", line));
	i = idx + 2;
	while (is_space(line[i]))
		i++;
	if (!(path = ft_substr(line, i, word_size(line, i))) || !path_open(path))
		show_error(1, win, ft_strjoin("Error\nwrong line : ", line));
	if (wf->c0 == 'N' && wf->c1 == 'O')
		return (set_texture(win, path, 0, wf));
	else if (wf->c0 == 'S' && wf->c1 == 'O')
		return (set_texture(win, path, 1, wf));
	else if (wf->c0 == 'W' && wf->c1 == 'E')
		return (set_texture(win, path, 2, wf));
	else if (wf->c0 == 'E' && wf->c1 == 'A')
		return (set_texture(win, path, 3, wf));
	else if (wf->c0 == 'S' && wf->c1 == ' ')
		return (stock_sprite(path, win, wf));
	else if (wf->c0 == 'H' && wf->c1 == ' ')
		return (set_texture(win, path, 4, wf));
	free(path);
	free(wf);
	return (SUCCES);
}

int		read_map1(char *line, int idx, t_win *win)
{
	t_w_front *wf;

	if (!(wf = malloc(sizeof(t_w_front))))
		return (ERROR);
	if (line[idx] && line[idx + 1])
	{
		wf->c0 = line[idx];
		wf->c1 = line[idx + 1];
	}
	else
		return (free_return(wf, NEXT));
	if (wf->c0 == 'R')
		return (read_resol(line, win, wf));
	else if ((line[idx] == 'N') || (line[idx] == 'S') || (line[idx] == 'W')
			|| (line[idx] == 'E') || (line[idx] == 'H'))
		return (read_path(line, wf, idx, win));
	if (line[idx] == 'F' || line[idx] == 'C')
	{
		free(wf);
		return (read_color(line, line[idx], idx, win));
	}
	return (free_return(wf, NEXT));
}

int		get_infos(char *line, char **map, int ret, t_win *win)
{
	int		i;
	int		ret2;

	i = 0;
	while (is_space(line[i]))
		i++;
	if (win->m_start_space == 1 && line[i] != '\0')
		show_error(1, win, "Error\nmap information is error");
	if (!(ret2 = read_map1(line, i, win)))
		return (ERROR);
	if (ret2 == NEXT)
	{
		if (is_map(line, map, i, ret))
		{
			win->map_start = 1;
			return (SUCCES);
		}
		else
			is_other(line, i, win);
	}
	return (SUCCES);
}

char	*treat_desc(const char *map_name, t_win *win)
{
	char	*line;
	char	*map;
	int		fd;
	int		ret;

	if ((fd = open(map_name, O_RDONLY)) == -1)
		show_error(1, win, "open is error");
	if (!(map = malloc(2)))
		return (ERROR);
	ft_bzero(map, sizeof(char));
	while ((ret = get_next_line(fd, &line)) != -1)
	{
		if (line && !get_infos(line, &map, ret, win))
		{
			free(line);
			return (ERROR);
		}
		if (ret == 0)
			break ;
		free(line);
	}
	free(line);
	return (map);
}
