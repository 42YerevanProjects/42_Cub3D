#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include <../mlx/mlx.h>

struct	s_map
{
	char	**map;
	char	*fd_no;
	char	*fd_so;
	char	*fd_we;
	char	*fd_ea;
	int		height;
	int		width;
	int		count;
	int		ceiling;
	int		floor;
	int		gnl;
	int		f;
	int		c;
}		map;

struct	s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	dir;
	char	dir_symb;
	int		count;
}		player;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}				t_data;

struct	s_win
{
	void	*mlx;
	void	*win;
	t_data	data;
	t_data	north;
	t_data	south;
	t_data	west;
	t_data	east;
	double	time;
	double	old_time;
	int		s_height;
	int		s_width;	
}		win;

typedef	struct	s_vars
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	double	tex_pos;
	double	step;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		tex_x;
	int		tex_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		side;
	int		hit;
}				t_vars;

/* UTILS */
int		get_next_line(int fd, char **line);
int		ft_atoi(const char *str);
char	*ft_strdup(char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, int start, int len);
int		get_count(char const *, char c);
void	ft_exit(int code);
int		ft_strlen(char *str);
char	**free_matrix(char **s);
int		is_valid(char *file);
int		is_empty(char *line);
int		f_open(char *file);
int		my_rgb(int r, int g, int b);

/* PARSING */
void	parse(char *file);
void	create_map(void);
void	init_map_size(char *file);
int		parse_colors(char **temp);
int		parse_elements(char *line);
void	fill_map(char *line, int n);

#endif
