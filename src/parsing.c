#include "../includes/cub3d.h"

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
				init_map_size(fd);
				create_map();
			}
			//TODO: parse line
			n++;
		}
	}
}
