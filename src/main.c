/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:35:27 by shovsepy          #+#    #+#             */
/*   Updated: 2022/03/29 07:35:59 by shovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	win.s_height = 1100;
	win.s_width = 1280;
	if (argc != 2)
		ft_exit(1);
	if (!is_valid(argv[1]))
		ft_exit(2);
	parse(argv[1]);
	return (0);
}
