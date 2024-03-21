/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:31:16 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/21 18:42:21 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	ray_allocation_failure(t_cub *cub, int ray_index)
{
	while (--ray_index > -1)
		free(cub->rays[ray_index]);
	exit (EXIT_FAILURE);
}

void	free_rays(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < N_RAYS)
		free(cub->rays[i]);
}

t_ray	*raycasting(t_cub *cub, int ray_index)
{
	t_ray		*ray;
	const int	map_x = (int)cub->player.pos_x;
	const int	map_y = (int)cub->player.pos_y;


	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	define_ray_dir(cub, ray);
	define_ray_delta(ray);
	define_ray_side_dist(ray, cub->player.pos_x, cub->player.pos_y);
	dda(cub, ray, map_x, map_y);
	return (ray);
}
