/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:09:36 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/24 19:30:43 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	square_size_and_border(t_cub *cub)
{
	int	x;
	int	y;

	x = MINI_WIDTH / cub->level.x_size;
	y = MINI_HEIGHT / cub->level.y_size;
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
	rectangle_fill(cub->mini.wall, WHITE);
	rectangle_fill(cub->mini.floor, BLACK);
	rectangle_fill(cub->mini.player, BLUE);
	draw_map(cub);
}
