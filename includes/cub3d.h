/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <aabajyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:29:51 by shovsepy          #+#    #+#             */
/*   Updated: 2022/04/03 09:57:03 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <../mlx/mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* GRAPHICS */
typedef int8_t		t_s8;
typedef uint8_t		t_u8;
typedef int16_t		t_s16;
typedef uint16_t	t_u16;
typedef int32_t		t_s32;
typedef uint32_t	t_u32;
typedef int64_t		t_s64;
typedef uint64_t	t_u64;

typedef uint32_t	t_color;
typedef void		t_mlx;
typedef void		t_mlx_window;

# if __APPLE__
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_RIGHT 124
#  define KEY_LEFT 123
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define FULL_OPACITY 0
#  define ROT_SPEED 0.063
#  define SPEED 0.069
# elif __linux__
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_RIGHT 65363
#  define KEY_LEFT 65361
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define FULL_OPACITY 255
#  define ROT_SPEED 0.033
#  define SPEED 0.039
# else
#  error "Unknown compiler"
# endif

# define MOVE_LEFT 1U
# define MOVE_RIGHT 2U
# define MOVE_UP 4U
# define MOVE_DOWN 8U

# define WIDTH 1024
# define HEIGHT 512

# define E_KEY_PRESS 2
# define E_KEY_RELEASE 3
# define E_BUTTON_PRESS 4
# define E_BUTTON_RELEASE 5
# define E_MOTION_NOTIFY 6
# define E_ENTER_NOTIFY 7
# define E_LEAVE_NOTIFY 8
# define E_FOCUS_IN 9
# define E_FOCUS_OUT 10
# define E_KEYMAP_NOTIFY 11
# define E_EXPOSE 12
# define E_GRAPHICS_EXPOSE 13
# define E_NO_EXPOSE 14
# define E_VISIBLITY_NOTIFY 15
# define E_CREATE_NOTIFY 16
# define E_DESTROY_NOTIFY 17
# define E_UNMAP_NOTIFY 18
# define E_MAP_NOTIFY 19
# define E_MAP_REQUEST 20
# define E_REPARENT_NOTIFY 21
# define E_CONFIGURE_NOTIFY 22
# define E_CONGIGURE_REQUEST 23
# define E_GRAVITY_NOTIFY 24
# define E_RESIZE_REQUEST 25
# define E_CIRCULATE_NOTIFY 26
# define E_CIRCULATE_REQUEST 27
# define E_PROPERTY_NOTIFY 28
# define E_SELECTION_CLEAR 29
# define E_SELECTION_REQUEST 30
# define E_SELECTION_NOTIFTY 31
# define E_COLORMAP_NOTIFY 32
# define E_CLIENT_MESSAGE 33
# define E_MAPPING_NOTIFY 34
# define E_GENERIC_EVENT 35
# define E_LAST_EVENT 36

# define M_NO_MASK 0L
# define M_KEY_PRESS 1L
# define M_KEY_RELEASE 2L
# define M_BUTTON_PRESS 4L
# define M_BUTTON_RELEASE 8L
# define M_WINDOW_ENTER 16L
# define M_WINDOW_LEAVE 32L
# define M_POINTER_MOTION 64L
# define M_POINTER_MOTION_HINT 128L
# define M_BUTTON_1_MOTION 256L
# define M_BUTTON_2_MOTION 512L
# define M_BUTTON_3_MOTION 1024L
# define M_BUTTON_4_MOTION 2048L
# define M_BUTTON_5_MOTION 4096L
# define M_BUTTON_MOTION 8192L
# define M_KEYMAP_STATE 16384L
# define M_EXPOSURE 32768L
# define M_VISIBILITY_CHANGE 65536L
# define M_STRUCTURE_NOTIFY 131072L
# define M_RESIZE_REDIRECT 262144L
# define M_SUBSTRUCTURE_NOTIFY 524288L
# define M_SUBSTRUCTURE_REDIRECT 1048576L
# define M_FOCUS_CHANGE 2097152L
# define M_PROPERTY_CHANGE 4194304L
# define M_COLORMAP_CHANGE 8388608L
# define M_OWNER_GRAB_BUTTON 16777216L

typedef struct s_rect
{
	int				x;
	int				y;
	int				width;
	int				height;
}					t_rect;

typedef struct s_vector
{
	int				x;
	int				y;
}					t_vector;

typedef struct s_fvector
{
	double			x;
	double			y;
}					t_fvector;

struct				s_map
{
	char			**map;
	char			*fd_no;
	char			*fd_so;
	char			*fd_we;
	char			*fd_ea;
	int				height;
	int				width;
	int				count;
	int				ceiling;
	int				floor;
	int				gnl;
	int				f;
	int				c;
}					map;

# define PLAYER_LEFT 1
# define PLAYER_RIGHT 2
# define PLAYER_UP 4
# define PLAYER_DOWN 8

struct				s_player
{
	double			x;
	double			y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			dir;
	char			dir_symb;
	int				count;
	int				move;
}					player;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				length;
	int				endian;
}					t_data;

# define DIRECTION_NORTH 0
# define DIRECTION_SOUTH 1
# define DIRECTION_WEST 2
# define DIRECTION_EAST 3

struct				s_win
{
	t_mlx			*mlx;
	t_mlx_window	*win;
	t_data			data;
	t_data			north;
	t_data			south;
	t_data			west;
	t_data			east;
	t_color			north_pixels[64][64];
	t_color			south_pixels[64][64];
	t_color			west_pixels[64][64];
	t_color			east_pixels[64][64];
	double			time;
	double			old_time;
	int				height;
	int				width;
}					win;

typedef struct s_vars
{
	int				direction;
	int				horizontal;
	int				vertical;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	double			wall_x;
	double			tex_pos;
	double			step;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				tex_x;
	int				tex_y;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				side;
	int				hit;
}					t_vars;

/* UTILS */
int					get_next_line(int fd, char **line);
int					ft_atoi(const char *str);
char				*ft_strdup(char *str);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, int start, int len);
int					get_count(char const *s, char c);
void				ft_exit(int code);
int					ft_strlen(char *str);
char				**free_matrix(char **s);
int					is_valid(char *file);
int					is_empty(char *line);
int					f_open(char *file);
int					my_rgb(int r, int g, int b);
void				check_zero(char *line);
void				check_validity(char c);
void				check_neighbours(int i, int j);
void				cleanup(void);

/* PARSING */
void				parse(char *file);
void				create_map(void);
void				init_map_size(char *file);
int					parse_colors(char **temp);
int					parse_elements(char *line);
void				fill_map(char *line, int n);
void				parse_cell(int i, int j);
int					parse_map(void);

/* EVENTS */
int					on_close(void);
int					on_key_press(int keycode);
int					on_key_release(int keycode);
int					on_loop(t_vars *vars);

void				player_move(void);
void				raycaster(t_vars *vars);

t_color				rgba(t_u8 r, t_u8 g, t_u8 b, t_u8 a);
t_color				rgb(t_u8 r, t_u8 g, t_u8 b);
t_vector			vector(int x, int y);
t_fvector			fvector(float x, float y);
t_rect				rect(int x, int y, int w, int h);
void				draw_pixel(int x, int y, t_color c);
t_color				get_pixel(t_data *dest, int x, int y);
void				draw_line(t_vector pos1, t_vector pos2, t_color c);
void				draw_rect(t_rect rect, t_color c);
void				texture_load(char *path, t_data *dest);
void				texture_to_array(t_data *src, t_color target[64][64]);
void				draw_texture(t_color t[64][64], int x, t_vars *vars);
void				do_sync(void);

#endif
