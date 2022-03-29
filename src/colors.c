/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:35:09 by shovsepy          #+#    #+#             */
/*   Updated: 2022/03/29 07:35:20 by shovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_color(char	**temp)
{
	char	**rgb;
	int		color;
	int		r;
	int		g;
	int		b;

	if (get_count(temp[1], ',') != 2)
	{
		free_matrix(temp);
		ft_exit(7);
	}
	rgb = ft_split(temp[1], ',');
	if (!rgb[0] || !rgb[1] || !rgb[2])
		ft_exit(7);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255
		|| b < 0 || b > 255)
		ft_exit(7);
	color = my_rgb(r, g, b);
	free_matrix(rgb);
	map.count++;
	return (color);
}

int	parse_colors_1(char **temp)
{
	if (temp[0][0] == 'N' && temp[0][1] == 'O' && temp[0][2] == '\0')
		map.fd_no = ft_strdup(temp[1]);
	else if (temp[0][0] == 'S' && temp[0][1] == 'O' && temp[0][2] == '\0')
		map.fd_so = ft_strdup(temp[1]);
	else if (temp[0][0] == 'W' && temp[0][1] == 'E' && temp[0][2] == '\0')
		map.fd_we = ft_strdup(temp[1]);
	else if (temp[0][0] == 'E' && temp[0][1] == 'A' && temp[0][2] == '\0')
		map.fd_ea = ft_strdup(temp[1]);
	else if (temp[0][0] == 'F' && temp[0][1] == '\0')
	{
		if (map.f >= 1)
			ft_exit(3);
		map.floor = parse_color(temp);
		map.f++;
	}
	else if (temp[0][0] == 'C' && temp[0][1] == '\0')
	{
		if (map.c >= 1)
			ft_exit(6);
		map.ceiling = parse_color(temp);
		map.c++;
	}
	else
		return (1);
	return (0);
}

int	parse_colors(char **temp)
{
	if (parse_colors_1(temp))
		return (1);
	free_matrix(temp);
	map.count = 6;
	return (0);
}
