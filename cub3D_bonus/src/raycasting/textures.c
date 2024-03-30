/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:27:36 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/29 09:53:12 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_texture(t_cub *cub, t_ray *ray)
{
	double	wall_x;
	double	tex_width;

	if (ray->side == EAST)
	{
		wall_x = cub->player.pos_y + ray->perp_wall_dist * ray->dir_y;
		tex_width = (double)cub->render->ea->width;
	}
	else if (ray->side == WEST)
	{
		wall_x = cub->player.pos_y + ray->perp_wall_dist * ray->dir_y;
		tex_width = (double)cub->render->we->width;
	}
	else if (ray->side == NORTH)
	{
		wall_x = cub->player.pos_x + ray->perp_wall_dist * ray->dir_x;
		tex_width = (double)cub->render->no->width;
	}
	else
	{
		wall_x = cub->player.pos_x + ray->perp_wall_dist * ray->dir_x;
		tex_width = (double)cub->render->so->width;
	}
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * (tex_width - 1));
}

void	door_texture(t_cub *cub, t_ray *ray)
{
	double	door_x;
	double	tex_width;

	tex_width = (double)cub->render->door->width;
	if (ray->side == EAST || ray->side == WEST)
		door_x = cub->player.pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		door_x = cub->player.pos_x + ray->perp_wall_dist * ray->dir_x;
	door_x -= floor(door_x);
	ray->tex_x = (int)(door_x * (tex_width - 1));
}

void	texture_x(t_cub *cub, t_ray *ray)
{
	if (ray->obj == '1')
		wall_texture(cub, ray);
	else if (ray->obj == 'D')
		door_texture(cub, ray);
}
