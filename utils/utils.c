#include "../includes/cub3d.h"

int	f_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd = -1)
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
