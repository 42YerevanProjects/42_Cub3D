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

int		parse_line(char *line, int n)
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


void	parse(char	*file)
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
	}
	//TODO: continue reading and parsing map
}
