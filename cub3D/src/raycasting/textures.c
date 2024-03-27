/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:27:36 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/27 18:05:05 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	textures_to_images(t_cub *cub)
{
	mlx_texture_t	*tex;

	tex = mlx_load_png(cub->level.no);
}

void	texture_fill(mlx_image_t *img, mlx_texture_t *tex, int start)
{
	uint32_t 	i;
	uint32_t 	j;
	uint32_t	color;
	uint8_t		*p;

	i = -1;
	while (++i < img->height)
	{
		j = -1;
		while (++j < img->width)
		{
			p = tex->pixels + 4 * (i * tex->width + start + j);
			color = color_rgba(*p, *(p + 1), *(p + 2), *(p + 3));
			mlx_put_pixel(img, i, j, color);
		}
	}
}