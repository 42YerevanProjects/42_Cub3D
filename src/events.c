/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <aabajyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:38:38 by aabajyan          #+#    #+#             */
/*   Updated: 2022/03/30 13:03:12 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_close(void)
{
	mlx_destroy_window(win.mlx, win.win);
	exit(0);
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
	printf("press: %d\n", player.move);
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
	printf("press: %d\n", player.move);
	return (0);
}
