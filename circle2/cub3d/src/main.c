/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:02:48 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/29 14:43:53 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	show_argv(void)
{
	ft_putstr("\n./cub3d map.cub");
	ft_putstr(".cub3d map.cub --save\n");
	exit(-1);
}

void	need_save(t_win *win_infos, char **argv)
{
	if (ft_strlen(argv[2]) > 0)
	{
		if (!(ft_strcmp(argv[2], "--save")))
		{
			win_infos->save = 1;
			raycasting(win_infos);
		}
		else
			show_argv();
	}
	else
		win_infos->save = 0;
}

void	show_error(int mod, t_win *win, char *msg)
{
	int	i;

	if (mod == 0)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	ft_putstr(msg);
	i = -1;
	/*
	while (++i < 5)
		free(win->tex[i]);
	free(win->tex);
	free(win->sprite);
	free(win->spr_screen);
	free(win->keybuffer);
	free(win->player);
	free(win->img);
	i = -1;
	while (++i < win->map->height)
		free(win->map->map[i]);
	free(win->map);
	free(win);
	*/
	exit(0);
}

int		check_cub(char *s)
{
	int	str_end;

	str_end = ft_strlen(s);
	if (s[str_end - 3] != 'c' || s[str_end - 2] != 'u' || s[str_end - 1] != 'b')
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_win	*win;

	if (argc < 2 || !check_cub(argv[1]))
		show_argv();
	if (!(win = init_game_window_pone()) || !init_game_tex(win, 5)
		|| !init_game_sprite(win) || !init_game_map(win, argv[1])
		|| !init_game_keybuffer(win) || !init_game_player(win)
		|| !init_game_window_ptwo(win))
		show_error(1, win, "");
	need_save(win, argv);
	mlx_hook(win->win_ptr, 2, 1L << 0, event_key_pressed, win);
	mlx_hook(win->win_ptr, 3, 1L << 1, event_key_released, win);
	mlx_hook(win->win_ptr, 17, 1L << 17, event_destroy_window, win);
	mlx_loop_hook(win->mlx_ptr, loop_manager, win);
	if (win->save != 1)
		mlx_loop(win->mlx_ptr);
	show_error(0, win, "");
	return (0);
}
