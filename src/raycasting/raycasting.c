/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:41:45 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/20 13:51:33 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	define_ray_delta(t_ray *ray)
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

void	define_ray_side_dist(t_ray *ray, double pos_x, double pos_y)
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

void	define_ray_dir(t_cub *cub, t_ray *ray)
{
	double		cam_x;

	cam_x = 2 * ray->index / (N_RAYS - 1) - 1;
	ray->dir_x = cub->player.dir_x + cam_x * cub->plane.x;
	ray->dir_y = cub->player.dir_y + cam_x * cub->plane.y;
}

void	dda(t_cub *cub, t_ray *ray, int map_x, int map_y)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			map_x += ray->step_x;
			ray->side = ray->step_x << 1;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			map_y += ray->step_y;
			ray->side = ray->step_y;
		}
		if (cub->level.map[map_y][map_x] == '1')
			hit = 1;
	}
}

void	raycast_loop(t_cub *cub)
{
	int			i;
	t_ray		*ray;
	const int	map_x = (int)cub->player.pos_x;
	const int	map_y = (int)cub->player.pos_y;

	i = -1;
	while (++i < N_RAYS)
	{
		ray = malloc(sizeof(t_ray));
		if (!ray)
			exit(EXIT_FAILURE);
		ray->index = i;
		define_ray_dir(cub, ray);
		define_ray_delta(ray);
		define_ray_side_dist(ray, cub->player.pos_x, cub->player.pos_y);
		dda(cub, ray, map_x, map_y);
	}
}

void	raycasting(t_cub *cub)
{
	set_initial_player_pos(cub);
	set_initial_plane(cub);
	raycast_loop(cub);
}
