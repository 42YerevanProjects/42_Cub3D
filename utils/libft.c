#include "../includes/cub3d.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		len++;
	return (len);
}

int	get_next_line(int fd, char **line)
{
	int		i;
	int		n;
	char	c;
	char	*str;

	i = 0;
	if (fd < 0)
		return (-1);
	str = (char *)malloc(1000 + 1);
	if (!str)
		return (-1);
	n = read(fd, &c, 1);
	while (n && c != '\n' && c != '\0')
	{
		str[i++] = c;
		n = read(fd, &c, 1);
	}
	str[i] = '\0';
	*line = str;
	if (ft_strlen(*line) != 0 && n == 0)
		map.gnl = 1;
	return (n);
}
