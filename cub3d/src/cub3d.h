/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:13:32 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/28 11:21:12 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define ESC 53
# define TOWARD 13
# define BACKWARD 1
# define LEFT 123
# define RIGHT 124
# define CAM_LEFT 0
# define CAM_RIGHT 2
# define CAMUP 126
# define CAMDOWN 125
# define ERROR 0
# define SUCCES 1
# define NEXT 2
# define BUFFER_SIZE 128

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <time.h>

# include <stdio.h>

typedef struct		s_sprite
{
	int				x;
	int				y;
}					t_sprite;

typedef struct		s_spr
{
	int				x;
	int				y;
	struct s_spr	*next;
}					t_sprites;

typedef struct		s_draw_sprite
{
	t_sprite		*sprites;
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			trans_x;
	double			trans_y;
	int				i;
	int				spr_sc_x;
	int				spr_h;
	int				draw_start_y;
	int				draw_end_y;
	int				spr_w;
	int				draw_start_x;
	int				draw_end_x;
	int				stripe;
	int				y;
	int				d;
	int				tex_x;
	int				tex_y;
	int				color;
	int				totcolor;
}					t_draw_sprite;

typedef struct		s_line
{
	int				x;
	int				y;
	int				y0;
	int				y1;
	int				tex_x;
	int				tex_y;
}					t_line;

typedef struct		s_front_char
{
	char			c0;
	char			c1;
}					t_w_front;

typedef struct		s_ray
{
	double			camera_x;
	double			rdx;
	double			rdy;
	double			sdx;
	double			sdy;
	double			ddx;
	double			ddy;
	double			pwd;
	double			*z_buffer;
	int				pix;
	int				mapx;
	int				mapy;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_ray;

typedef struct		s_image
{
	void			*img_ptr;
	char			*data;
	int				width;
	int				height;
	int				size_line;
	int				bpp;
	int				endian;
}					t_image;

typedef struct		s_keybuffer
{
	int				toward;
	int				backward;
	int				left;
	int				right;
	int				turn_left;
	int				turn_right;
	int				cam_up;
	int				cam_down;
}					t_keybuffer;

typedef struct		s_map
{
	const char		*map_name;
	char			**map;
	int				width;
	int				height;
}					t_map;

typedef	struct		s_player
{
	double			posx;
	double			posy;
	double			speed;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			rot_speed;
	double			cam_height;
	int				health;
}					t_player;

typedef	struct		s_window
{
	t_map			*map;
	t_keybuffer		*keybuffer;
	t_player		*player;
	t_image			*img;
	t_image			**tex;
	t_image			*sprite;
	t_sprites		*spr_screen;
	void			*mlx_ptr;
	void			*win_ptr;
	int				width;
	int				height;
	int				col_flo;
	int				col_ceil;
	int				save;
	int				map_start;
	int				m_start_space;
}					t_win;

void				set_start_pos(t_win *win, char dir, int x, int y);
void				set_start_came(t_win *win, double dirx, double planex,
	double planey);
void				hit(t_ray *ray, t_win *win);
void				perp_and_height(t_ray *ray, t_player *player, t_win *win);
void				pixel_put_to_image(int color, int x, int y, t_image *img);
void				make_sprite(t_draw_sprite *ds, t_win *win, t_ray *ray);
void				texturisation(t_ray *ray, t_win *win);
void				predict_wall_face(t_ray *ray);
void				is_sprite(t_ray *ray, t_win *win);
void				show_argv(void);
void				turn_left(t_win *win);
void				turn_right(t_win *win);
void				show_error(int mod, t_win *win, char *msg);

t_win				*init_game_window_pone(void);

char				**read_map2(char *str, t_win *win);
char				*treat_desc(const char *map_name, t_win *win);

int					init_game_tex(t_win *win, int n);
int					init_game_sprite(t_win *win);
int					init_game_map(t_win *win, char *map_name);
int					init_game_keybuffer(t_win *win);
int					init_game_player(t_win *win);
int					init_game_window_ptwo(t_win *win);
int					get_infos(char *line, char **map, int ret, t_win *win);
int					read_map1(char *line, int idx, t_win *win);
int					read_resol(char *line, t_win *win, t_w_front *wf);
int					check_resol(char *s);
int					read_path(char *line, t_w_front *wf, int idx, t_win *win);
int					check_path(char *s);
int					path_open(const char *path);
int					set_texture(t_win *win, char *path, int idx, t_w_front *wf);
int					stock_sprite(char *path, t_win *win, t_w_front *wf);
int					check_color(char *s, int c, int idx, t_win *win);
int					read_color(char *line, int c, int idx, t_win *win);
int					is_map(char *l, char **map, int i, int ret);
int					is_other(char *line, int idx, t_win *win);
int					check_map(t_win *win, char **map);
int					raycasting(t_win *win);
int					draw_sprite(t_ray *ray, t_win *win);
int					create_bitmap(t_image *mlx_img, char *name);
int					event_key_pressed(int key, void *param);
int					event_key_released(int key, void *param);
int					event_destroy_window(void *param);
int					loop_manager(void *param);
int					key_manager(t_win *win);
int					free_return(void *p, int ret);

#endif
