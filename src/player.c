/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <aabajyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:03:07 by aabajyan          #+#    #+#             */
/*   Updated: 2022/03/31 00:04:37 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_move(void)
{
	if ((player.move & MOVE_LEFT) != 0)
		player.x -= 5;
	if ((player.move & MOVE_RIGHT) != 0)
		player.x += 5;
	if ((player.move & MOVE_UP) != 0)
		player.y -= 5;
	if ((player.move & MOVE_DOWN) != 0)
		player.y += 5;
}
