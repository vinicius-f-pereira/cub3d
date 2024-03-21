/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:41:45 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/21 16:25:40 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	define_ray_delta(t_ray *ray)
{
	if (ray->dir_x == 0)
		ray->delta_dist_x = INFINITY;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = INFINITY;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
}

static void	define_ray_side_dist(t_ray *ray, double pos_x, double pos_y)
{
	const double	map_x = (double)(int)pos_x;
	const double	map_y = (double)(int)pos_y;

	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (pos_x - map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (map_x + 1.0 - pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (pos_y - map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (map_y + 1.0 - pos_y) * ray->delta_dist_y;
	}
}

static void	define_ray_dir(t_cub *cub, t_ray *ray)
{
	double		cam_x;

	cam_x = 2 * ray->index / (N_RAYS - 1.0) - 1.0;
	ray->dir_x = cub->player.dir_x + cam_x * cub->plane.x;
	ray->dir_y = cub->player.dir_y + cam_x * cub->plane.y;
}

static void	dda(t_cub *cub, t_ray *ray, int map_x, int map_y)
{
	while (1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			map_x += ray->step_x;
			ray->side = ray->step_x;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			map_y += ray->step_y;
			ray->side = ray->step_y * 2;
		}
		if (cub->level.map[map_y][map_x] == '1')
			break ;
	}
	if (ray->side == EAST || ray->side == WEST)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

void	raycasting(t_cub *cub)
{
	set_initial_player_pos(cub);
	set_initial_plane(cub);
	raycast_loop(cub);
}
