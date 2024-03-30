/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:09:36 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/29 23:32:46 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "MLX42.h"
#include "cub3d.h"

void	minimap_square_size_and_border(t_cub *cub)
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

	side = cub->mini.side;
	if (cub->mini.wall)
		mlx_delete_image(cub->mlx, cub->mini.wall);
	cub->mini.wall = mlx_new_image(cub->mlx, side, side);
	rectangle_fill(cub->mini.wall, WALL_COLOR);
	if (cub->mini.floor)
		mlx_delete_image(cub->mlx, cub->mini.floor);
	cub->mini.floor = mlx_new_image(cub->mlx, side, side);
	rectangle_fill(cub->mini.floor, FLOOR_COLOR);
	if (cub->mini.player)
		mlx_delete_image(cub->mlx, cub->mini.player);
	cub->mini.player = mlx_new_image(cub->mlx, side / 2, side / 2);
	rectangle_fill(cub->mini.player, PLAYER_COLOR);
	draw_map(cub);
}

void	knife(t_cub *cub)
{
	double time;

	time = mlx_get_time();
	if (cub->weapon.walk)
		mlx_delete_image(cub->mlx, cub->weapon.walk);
	if (cub->weapon.attack)
		mlx_delete_image(cub->mlx, cub->weapon.attack);
	cub->weapon.walk = mlx_texture_to_image(cub->mlx, cub->render->knife2);
	cub->weapon.attack = mlx_texture_to_image(cub->mlx, cub->render->knife1);
	mlx_resize_image(cub->weapon.walk, 250, 250);
	mlx_resize_image(cub->weapon.attack, 250, 250);
	draw_map(cub);
	mlx_image_to_window(cub->mlx, cub->weapon.walk, 250, 350);
	if ((int)time % 2 == 0)
	{
		mlx_delete_image(cub->mlx, cub->weapon.walk);
		draw_map(cub);
		mlx_image_to_window(cub->mlx, cub->weapon.attack, 250, 350);
	}
}
