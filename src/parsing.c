/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <aabajyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:36:50 by shovsepy          #+#    #+#             */
/*   Updated: 2022/03/31 17:14:38 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_elements(char *line)
{
	char	**temp;

	temp = ft_split(line, ' ');
	if (temp[2] != NULL)
	{
		free_matrix(temp);
		ft_exit(6);
	}
	if (parse_colors(temp))
	{
		free_matrix(temp);
		return (1);
	}
	return (0);
}

int	parse_line(char *line, int n)
{
	if (n >= 0 && n <= 5)
	{
		if (parse_elements(line))
			ft_exit(6);
		return (0);
	}
	else if (n > 5)
	{
		fill_map(line, n - 6);
		return (0);
	}
	return (1);
}

void	parse_cell(int i, int j)
{
	check_validity(map.map[i][j]);
	if (j == 0 || j == map.width - 1)
		if (map.map[i][j] != ' ' && map.map[i][j] != '1')
			ft_exit(4);
	if (map.map[i][j] == 'N' || map.map[i][j] == 'W'
		|| map.map[i][j] == 'E' || map.map[i][j] == 'S')
	{
		player.count++;
		if (player.count == 1)
		{
			player.x = j;
			player.y = i;
			player.dir_symb = map.map[i][j];
		}
		map.map[i][j] = '0';
	}
	if (map.map[i][j] == ' ')
		check_neighbours(i, j);
}

void	process_map(char *line, int n, int fd)
{
	if (map.gnl)
	{
		if (!is_empty(line))
			if (parse_line(line, n))
				ft_exit(4);
	}
	if (close(fd) == -1)
		ft_exit(8);
	if (map.count != 6)
		ft_exit(6);
	if (parse_map())
		ft_exit(6);
	free(line);
}

void	parse(char *file)
{
	int		n;
	int		fd;
	char	*line;

	n = 0;
	fd = f_open(file);
	while (get_next_line(fd, &line))
	{
		if (!is_empty(line))
		{
			if (n == 5)
			{
				init_map_size(file);
				create_map();
			}
			if (parse_line(line, n))
				ft_exit(4);
			n++;
		}
		if (line)
			free(line);
	}
	process_map(line, n, fd);
}
