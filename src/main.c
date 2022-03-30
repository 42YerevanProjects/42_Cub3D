/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <aabajyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:35:27 by shovsepy          #+#    #+#             */
/*   Updated: 2022/03/30 13:03:40 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	win.height = 1100;
	win.width = 1280;
	if (argc != 2)
		ft_exit(1);
	if (!is_valid(argv[1]))
		ft_exit(2);
	parse(argv[1]);
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, win.width, win.height, "Cub3d");
	win.data = mlx_new_image(win.mlx, win.width, win.height);
	player.move = 0;
	mlx_put_image_to_window(win.mlx, win.win, win.data, 0, 0);
	mlx_hook(win.win, E_DESTROY_NOTIFY, 0, on_close, NULL);
	mlx_hook(win.win, E_KEY_PRESS, M_KEY_PRESS, on_key_press, NULL);
	mlx_hook(win.win, E_KEY_RELEASE, M_KEY_RELEASE, on_key_release, NULL);
	mlx_loop(win.mlx);
	return (0);
}
