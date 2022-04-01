/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <aabajyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:09:22 by aabajyan          #+#    #+#             */
/*   Updated: 2022/04/01 20:27:48 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	raycaster_setup(int x, t_vars *vars)
{
	vars->camera_x = 2 * x / (double)WIDTH - 1;
	vars->ray_dir_x = player.dir_x + player.plane_x * vars->camera_x;
	vars->ray_dir_y = player.dir_y + player.plane_y * vars->camera_x;
	vars->map_x = (int)player.x;
	vars->map_y = (int)player.y;
	if (vars->ray_dir_x == 0)
		vars->delta_dist_x = 1e30;
	else
		vars->delta_dist_x = fabs(1 / vars->ray_dir_x);
	if (vars->ray_dir_y == 0)
		vars->delta_dist_y = 1e30;
	else
		vars->delta_dist_y = fabs(1 / vars->ray_dir_y);
	vars->hit = 0;
}

static void	raycaster_get_sides(t_vars *vars)
{
	if (vars->ray_dir_x < 0)
	{
		vars->step_x = -1;
		vars->side_dist_x = (player.x - vars->map_x) * vars->delta_dist_x;
		vars->vertical = DIRECTION_NORTH;
	}
	else
	{
		vars->step_x = 1;
		vars->side_dist_x = (vars->map_x + 1.0 - player.x) * vars->delta_dist_x;
		vars->vertical = DIRECTION_SOUTH;
	}
	if (vars->ray_dir_y < 0)
	{
		vars->step_y = -1;
		vars->side_dist_y = (player.y - vars->map_y) * vars->delta_dist_y;
		vars->horizontal = DIRECTION_WEST;
	}
	else
	{
		vars->step_y = 1;
		vars->side_dist_y = (vars->map_y + 1.0 - player.y) * vars->delta_dist_y;
		vars->horizontal = DIRECTION_EAST;
	}
}

static void	raycaster_dda(t_vars *vars)
{
	while (vars->hit == 0)
	{
		if (vars->side_dist_x < vars->side_dist_y)
		{
			vars->side_dist_x += vars->delta_dist_x;
			vars->map_x += vars->step_x;
			vars->side = 0;
		}
		else
		{
			vars->side_dist_y += vars->delta_dist_y;
			vars->map_y += vars->step_y;
			vars->side = 1;
		}
		if (vars->map_x < 0 || vars->map_x >= map.width
			|| vars->map_y < 0 || vars->map_y >= map.height)
			return ;
		if (map.map[vars->map_y][vars->map_x] == '1')
			vars->hit = 1;
	}
}

static void	raycaster_prepare_drawing(t_vars *vars)
{
	if (vars->side == 0)
	{
		vars->perp_wall_dist = vars->side_dist_x - vars->delta_dist_x;
		vars->direction = vars->vertical;
	}
	else
	{
		vars->perp_wall_dist = vars->side_dist_y - vars->delta_dist_y;
		vars->direction = vars->horizontal;
	}
	vars->line_height = (int)(HEIGHT / vars->perp_wall_dist);
	vars->draw_start = -vars->line_height / 2 + HEIGHT / 2;
	if (vars->draw_start < 0)
		vars->draw_start = 0;
	vars->draw_end = vars->line_height / 2 + HEIGHT / 2;
	if (vars->draw_end >= HEIGHT)
		vars->draw_end = HEIGHT - 1;
	if (vars->side == 0)
		vars->wall_x = player.y + vars->perp_wall_dist * vars->ray_dir_y;
	else
		vars->wall_x = player.x + vars->perp_wall_dist * vars->ray_dir_x;
	vars->wall_x -= floor(vars->wall_x);
	vars->tex_x = (int)(vars->wall_x * 64.0);
}

void	raycaster(t_vars *vars)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		raycaster_setup(x, vars);
		raycaster_get_sides(vars);
		raycaster_dda(vars);
		raycaster_prepare_drawing(vars);
		if ((vars->side == 0 && vars->ray_dir_x > 0)
			|| (vars->side == 1 && vars->ray_dir_y < 0))
			vars->tex_x = 64 - vars->tex_x - 1;
		vars->step = 64.0 / vars->line_height;
		vars->tex_pos = (vars->draw_start - HEIGHT / 2 + vars->line_height / 2)
			* vars->step;
		if (vars->direction == DIRECTION_NORTH)
			draw_texture(win.north_pixels, x, vars);
		else if (vars->direction == DIRECTION_EAST)
			draw_texture(win.east_pixels, x, vars);
		else if (vars->direction == DIRECTION_WEST)
			draw_texture(win.west_pixels, x, vars);
		else
			draw_texture(win.south_pixels, x, vars);
		++x;
	}
}
