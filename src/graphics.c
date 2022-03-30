/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <aabajyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:59:25 by aabajyan          #+#    #+#             */
/*   Updated: 2022/03/30 23:50:27 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	rgba(t_u8 r, t_u8 g, t_u8 b, t_u8 a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

void	pixel(int x, int y, t_color c)
{
	char			*dest;
	unsigned int	ppos;

	if (x < 0 || y < 0 || x >= win.height || y >= win.height)
		return ;
	ppos = y * win.data.length;
	ppos += x * (win.data.bpp / 8);
	dest = win.data.addr + ppos;
	*(t_u32 *)dest = c;
}

void	line(t_vector pos1, t_vector pos2, t_color c)
{
	t_vector	d;
	t_fvector	inc;
	int			steps;
	t_fvector	pos;
	int			i;

	d = (t_vector){pos2.x - pos1.x, pos2.y - pos1.y};
	if (abs(d.x) > abs(d.y))
		steps = abs(d.x);
	else
		steps = abs(d.y);
	inc = (t_fvector){d.x / (float)steps, d.y / (float)steps};
	pos = (t_fvector){pos1.x, pos1.y};
	i = 0;
	while (i <= steps)
	{
		pixel((int)round(pos.x), (int)round(pos.y), c);
		pos.x += inc.x;
		pos.y += inc.y;
		i++;
	}
}

void	rect(t_rect rect, t_color c)
{
	t_vector	pos1;
	t_vector	pos2;

	pos1 = (t_vector){rect.x, 0};
	pos2 = (t_vector){rect.x + rect.width, 0};
	while (rect.height-- > 0)
	{
		pos1.y = rect.y + rect.height;
		pos2.y = rect.y + rect.height;
		line(pos1, pos2, c);
	}
}

void	do_sync(void)
{
	mlx_put_image_to_window(win.mlx, win.win, win.data.img, 0, 0);
	mlx_do_sync(win.mlx);
}
