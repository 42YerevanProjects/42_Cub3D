#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	win.s_height = 1100;
	win.s_width = 1280;
	if (argc != 2)
		ft_exit(1);

	if (!is_valid(argv[1]))
		ft_exit(2);

	parse(argv[1]);
	return (0);

}
