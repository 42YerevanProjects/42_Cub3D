/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <aabajyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:03:21 by aabajyan          #+#    #+#             */
/*   Updated: 2022/04/03 10:03:32 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_map(void)
{
	int	y;

	y = 0;
	while (y < map.height)
		free(map.map[y++]);
	free(map.map);
}

void	cleanup(void)
{
	if (win.west.img)
		mlx_destroy_image(win.mlx, win.west.img);
	if (win.east.img)
		mlx_destroy_image(win.mlx, win.east.img);
	if (win.north.img)
		mlx_destroy_image(win.mlx, win.north.img);
	if (win.south.img)
		mlx_destroy_image(win.mlx, win.south.img);
	if (win.data.img)
		mlx_destroy_image(win.mlx, win.data.img);
	if (win.win)
		mlx_destroy_window(win.mlx, win.win);
	if (map.fd_ea)
		free(map.fd_ea);
	if (map.fd_no)
		free(map.fd_no);
	if (map.fd_so)
		free(map.fd_so);
	if (map.fd_we)
		free(map.fd_we);
	if (map.map)
		destroy_map();
}
