/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:41:45 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/19 14:57:26 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	define_rays_

void	define_rays_deltas(t_ray *ray)
{
	const double	int_pos_x = (double)(int)pos_x;
	const double	int_pos_y = (double)(int)pos_y;

	if (ray->dir_x == 0)
		ray->delta_dist_x = DBL_MAX;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = DBL_MAX;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
}

void	define_rays_dir(t_cub *cub)
{
	int			i;
	double		cam_x;
	t_ray		*ray;

	i = -1;
	while (++i < N_RAYS)
	{
		ray = ft_calloc(1, sizeof(t_ray));
		if (!ray)
			exit(EXIT_FAILURE);
		cam_x = 2 * i / (N_RAYS - 1) - 1;
		ray->dir_x = cub->player.dir_x + cam_x * cub->plane.x;
		ray->dir_y = cub->player.dir_y + cam_x * cub->plane.y;
	}
}
