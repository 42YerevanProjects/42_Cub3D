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
