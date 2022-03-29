/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:34:24 by shovsepy          #+#    #+#             */
/*   Updated: 2022/03/29 07:34:28 by shovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	f_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_exit(3);
	return (fd);
}

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	is_empty(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (!is_space(*str))
			return (0);
		str++;
	}
	return (1);
}

int	get_count(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s != '\0')
	{
		if (*s == c)
			cnt++;
		s++;
	}
	return (cnt);
}

int	my_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
