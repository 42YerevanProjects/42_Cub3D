/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <aabajyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:03:55 by aabajyan          #+#    #+#             */
/*   Updated: 2022/04/01 19:58:02 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	get_pixel(t_data *dest, int x, int y)
{
	int		color;
	char	*dst;

	if (!dest)
		return (0);
	dst = dest->addr + (y * dest->length + x * (dest->bpp / 8));
	color = *(t_color *)dst;
	return (color);
}

void	texture_to_array(t_data *src, t_color target[64][64])
{
	int	y;
	int	x;

	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			target[y][x] = get_pixel(src, x, y);
			++x;
		}
		++y;
	}
}

void	draw_texture(t_color t[64][64], int x, t_vars *vars)
{
	int		y;
	int		wall_y;
	t_color	c;

	y = vars->draw_start;
	while (y < vars->draw_end)
	{
		wall_y = (int)vars->tex_pos & (64 - 1);
		vars->tex_pos += vars->step;
		c = t[wall_y][vars->tex_x];
		if (vars->side == 1)
			c = (c >> 1) & 8355711;
		draw_pixel(x, y++, c);
	}
}

void	texture_load(char *path, t_data *dest)
{
	int	width;
	int	height;
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_exit(4);
	close(fd);
	dest->img = mlx_xpm_file_to_image(win.mlx, path, &width, &height);
	dest->addr = mlx_get_data_addr(dest->img, &dest->bpp, &dest->length,
			&dest->endian);
}
