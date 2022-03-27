#include "../includes/cub3d.h"

void	ft_exit(int code)
{
	if (code == 1)
		printf("Error: Invalid number of arguments!\n");
	else if (code == 2)
		printf("Error: The input file is missing the .cub extension!\n");
	else if (code == 3)
		printf("Error: Failed to open the .cub file!\n");
	else if (code == 4)
		printf("Error: The input file contains an invalid map!\n");
	else if (code == 5)
		printf("Error: Memory allocation is failed!\n");
	exit(code);
}
