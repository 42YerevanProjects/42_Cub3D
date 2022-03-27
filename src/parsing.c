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
			// TODO:  create map
			n++;
		}
	}
}
