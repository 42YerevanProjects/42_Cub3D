/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <aabajyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:38:38 by aabajyan          #+#    #+#             */
/*   Updated: 2022/03/30 14:42:15 by aabajyan         ###   ########.fr       */
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

char	*g_temp_map[] = {
	"        1111111111111111111111111",
	"        1000000000110000000000001",
	"        1011000001110000000000001",
	"        1001000000000000000000001",
	"111111111011000001110000000000001",
	"100000000011000001110111111111111",
	"11100011111111011100000010001",
	"11100011111111011101010010001",
	"11000000110101011100000010001",
	"10000000000000001100000000001",
	"1000N000000000001101010010001",
	"1100000111011101 11101111000011",
	"11110111 1110101 101111010001",
	"11111111 1111111 111111111111",
};

int	on_loop(void)
{
	rect((t_rect){0, 0, 500, 500}, rgba(255, 0, 0, FULL_OPACITY));
	do_sync();
	return (0);
}
