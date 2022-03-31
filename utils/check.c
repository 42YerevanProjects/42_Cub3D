/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <aabajyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:08:56 by aabajyan          #+#    #+#             */
/*   Updated: 2022/03/31 17:09:22 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_zero(char *line)
{
	if (!line)
		ft_exit(4);
	while (*line)
	{
		if (*line != ' ' && *line != '1' && *line != '\0')
			ft_exit(4);
		line++;
	}
}

void	check_validity(char c)
{
	if (c != ' ' && c != '1' && c != '0' && c != 'N' && c != 'W'
		&& c != 'E' && c != 'S')
		ft_exit(4);
}

void	check_neighbours(int i, int j)
{
	if (i - 1 >= 0 && i - 1 < map.height)
		if (map.map[i - 1][j] != ' ' && map.map[i - 1][j] != '1'
			&& map.map[i - 1][j] != '\0')
			ft_exit(4);
	if (i + 1 >= 0 && i + 1 < map.height)
		if (map.map[i + 1][j] != ' ' && map.map[i + 1][j] != '1'
			&& map.map[i + 1][j] != '\0')
			ft_exit(4);
	if (j - 1 >= 0 && j - 1 < map.width)
		if (map.map[i][j - 1] != ' ' && map.map[i][j - 1] != '1'
			&& map.map[i + 1][j] != '\0')
			ft_exit(4);
	if (j + 1 >= 0 && j + 1 < map.width)
		if (map.map[i][j + 1] != ' ' && map.map[i][j + 1] != '1'
			&& map.map[i + 1][j] != '\0')
			ft_exit(4);
}
