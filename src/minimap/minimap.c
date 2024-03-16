/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:09:36 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/15 22:10:33 by brmoretti        ###   ########.fr       */
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

void	square_size_and_border(t_cub *cub)
{
	int	x;
	int	y;

	x = MINI_WIDTH / cub->level.x_size;
	y = MINI_HEGHT / cub->level.y_size;
	if (x < y)
		cub->mini.side = x;
	else
		cub->mini.side = y;
	cub->mini.border = (float)cub->mini.side * BORDER;
	if (cub->mini.border <= 0)
		cub->mini.border = 1;
	cub->mini.side -= 2 * cub->mini.border;
}

void	minimap(t_cub *cub)
{
	int	side;

	square_size_and_border(cub);
	side = cub->mini.side;
	cub->mini.wall = mlx_new_image(cub->mlx, side, side);
	cub->mini.floor = mlx_new_image(cub->mlx, side, side);
	cub->mini.player = mlx_new_image(cub->mlx, side / 4, side / 4);
	square_constructor(cub->mini.wall, WHITE);
	square_constructor(cub->mini.floor, BLACK);
	square_constructor(cub->mini.player, BLUE);
	draw_map(cub);
	mlx_loop(cub->mlx);
}
