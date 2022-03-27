#include "../includes/cub3d.h"

void	ft_exit(int code)
{
	if (code == 1)
		printf("Invalid number of arguments!\n");
	else if (code == 2)
		printf("The input file is invalid. Missing the .cub extension!\n");
	else if (code == 3)
		printf("Failed to open the .cub file!\n");
	exit(code);
}
