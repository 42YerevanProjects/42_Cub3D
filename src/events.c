/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <aabajyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:38:38 by aabajyan          #+#    #+#             */
/*   Updated: 2022/04/03 10:05:46 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	on_close(void)
{
	ft_exit(0);
	return (0);
}

int	on_key_press(int keycode)
{
	if (keycode == KEY_ESC)
		return (on_close());
	if (keycode == KEY_LEFT || keycode == KEY_A)
		player.move |= PLAYER_LEFT;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		player.move |= PLAYER_RIGHT;
	else if (keycode == KEY_UP || keycode == KEY_W)
		player.move |= PLAYER_UP;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		player.move |= PLAYER_DOWN;
	return (0);
}

int	on_key_release(int keycode)
{
	if (keycode == KEY_ESC)
		return (on_close());
	if (keycode == KEY_LEFT || keycode == KEY_A)
		player.move &= ~PLAYER_LEFT;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		player.move &= ~PLAYER_RIGHT;
	else if (keycode == KEY_UP || keycode == KEY_W)
		player.move &= ~PLAYER_UP;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		player.move &= ~PLAYER_DOWN;
	return (0);
}

int	on_loop(t_vars *vars)
{
	int	y;
	int	x;

	player_move();
	draw_rect(rect(0, 0, win.width, win.height), rgb(0, 0, 0));
	draw_rect(rect(0, 0, WIDTH, HEIGHT / 2), map.ceiling);
	draw_rect(rect(0, HEIGHT / 2, WIDTH, HEIGHT / 2), map.floor);
	raycaster(vars);
	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			if (map.map[y][x] == '1')
				draw_rect(rect(x * 5, y * 5, 5, 5), rgb(100, 100, 100));
			++x;
		}
		++y;
	}
	draw_rect(rect(player.x * 5, player.y * 5, 3, 3), rgb(255, 255, 0));
	do_sync();
	return (0);
}
