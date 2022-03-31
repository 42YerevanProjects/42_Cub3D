/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <aabajyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:36:05 by shovsepy          #+#    #+#             */
/*   Updated: 2022/03/31 20:08:48 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	process_line(char *line, int *n, int flag)
{
	if (flag)
		ft_exit(4);
	if (*n < 6)
		(*n)++;
	else
	{
		if (ft_strlen(line) > map.width)
			map.width = ft_strlen(line);
		map.height++;
		(*n)++;
	}
}

void	init_map_size(char *file)
{
	int		n;
	int		fd;
	int		flag;
	char	*line;

	n = 0;
	flag = 0;
	fd = f_open(file);
	while (get_next_line(fd, &line))
	{
		if (!is_empty(line))
			process_line(line, &n, flag);
		else if (n > 6)
			flag = 1;
		free(line);
	}
	if (map.gnl)
		map.height++;
	free(line);
	close(fd);
}

void	create_map(void)
{
	int	i;

	i = 0;
	map.map = malloc((map.height + 1) * sizeof(char *));
	if (!map.map)
		ft_exit(5);
	while (i < map.height)
	{
		map.map[i] = malloc((map.width + 1) * sizeof(char *));
		if (!map.map[i])
			ft_exit(5);
		i++;
	}
}

void	fill_map(char *line, int n)
{
	int	i;

	i = -1;
	while (line[++i] != '\0')
		map.map[n][i] = line[i];
	while (i < map.width)
	{
		map.map[n][i] = ' ';
		i++;
	}
	map.map[n][i] = '\0';
}

int	parse_map(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map.height)
	{
		if (i == 0 || i == map.height - 1)
			check_zero(map.map[i]);
		j = -1;
		while (map.map[i][++j])
			parse_cell(i, j);
	}
	if (player.count == 0)
		ft_exit(4);
	return (0);
}
