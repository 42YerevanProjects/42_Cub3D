/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <aabajyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:59:25 by aabajyan          #+#    #+#             */
/*   Updated: 2022/03/30 14:42:21 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	rgba(t_u8 r, t_u8 g, t_u8 b, t_u8 a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

void	pixel(t_vector pos, t_color c)
{
	char			*dest;
	unsigned int	ppos;

	if (pos.x < 0 || pos.y < 0 || pos.x >= win.height || pos.y >= win.height)
		return ;
	ppos = pos.y * win.data.length;
	ppos += pos.x * (win.data.bpp / 8);
	dest = win.data.addr + ppos;
	*(t_u32 *)dest = c;
}

void	line(t_vector pos1, t_vector pos2, t_color c)
{
	t_vector	dpos;
	t_vector	pos;

	dpos = (t_vector){pos2.x - pos1.x, pos2.y - pos1.y};
	pos = (t_vector){pos1.x, 0};
	while (pos.x <= pos2.x)
	{
		pos.y = pos1.y + dpos.y * (pos.x - pos1.x) / dpos.x;
		pixel(pos, c);
		++pos.x;
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
