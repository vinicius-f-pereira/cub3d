/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:27:36 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/28 11:23:01 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	textures_to_images(t_cub *cub)
{
	mlx_texture_t	*tex;
	mlx_image_t		*img;
	int				width = 32;

	tex = mlx_load_png(cub->level.no);
	printf("h: %d w: %d\n", tex->height, tex->width);
	img = mlx_new_image(cub->mlx, width, tex->height);
	texture_fill(img, tex, 31);
	mlx_image_to_window(cub->mlx, img, 0, 0);
	mlx_resize_image(img, width * 5, 64 * 5);
}

void	texture_x(t_cub *cub, t_ray *ray)
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
	else if (ray->side == SOUTH)
	{
		wall_x = cub->player.pos_x + ray->perp_wall_dist * ray->dir_x;
		tex_width = (double)cub->render->so->width;
	}
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * tex_width);
}
