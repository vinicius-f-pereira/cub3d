/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:09:36 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/15 16:54:55 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

uint32_t	color_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	square_constructor(mlx_image_t *img, uint32_t color)
{
	uint32_t	i;
	uint32_t	j;

	i = -1;
	while (++i < img->width)
	{
		j = -1;
		while (++j < img->height)
			mlx_put_pixel(img, i, j, color);
	}
}

void	minimap(t_cub *cub)
{
	cub->mini.wall = mlx_new_image(cub->mlx, 30, 30);
	cub->mini.floor = mlx_new_image(cub->mlx, 30, 30);
	cub->mini.player = mlx_new_image(cub->mlx, 7, 7);
	square_constructor(cub->mini.wall, color_rgba(255, 255, 255, 255));
	square_constructor(cub->mini.floor, color_rgba(0, 0, 0, 255));
	square_constructor(cub->mini.player, color_rgba(0, 100, 0, 255));
	if (mlx_image_to_window(cub->mlx, cub->mini.wall, 385, 285) < 0)
		exit(99);
	if (mlx_image_to_window(cub->mlx, cub->mini.wall, 416, 285) < 0)
		exit(99);
	if (mlx_image_to_window(cub->mlx, cub->mini.floor, 385, 316) < 0)
		exit(99);
	if (mlx_image_to_window(cub->mlx, cub->mini.floor, 416, 316) < 0)
		exit(99);
	if (mlx_image_to_window(cub->mlx, cub->mini.player, 417, 317) < 0)
		exit(99);
	mlx_loop(cub->mlx);
}
