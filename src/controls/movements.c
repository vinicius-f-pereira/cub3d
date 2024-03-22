/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:19:46 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/22 17:20:58 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	wasd(t_cub *cub, keys_t key)
{
	double	dir_x;
	double	dir_y;

	dir_x = cub->player.dir_x;
	dir_y = cub->player.dir_y;
	if (key == MLX_KEY_A || key == MLX_KEY_D)
		rotate(&dir_x, &dir_y, M_PI / 2);
	if (key == MLX_KEY_S || key == MLX_KEY_A)
	{
		dir_x *= -1;
		dir_y *= -1;
	}
	cub->player.pos_x += dir_x * LINEAR_SPEED;
	cub->player.pos_y += dir_y * LINEAR_SPEED;
}

static void	player_plane_rotation(t_cub *cub, int direction)
{
	double	speed;

	speed = (double)direction * ANGULAR_SPEED;
	rotate(&cub->player.dir_x, &cub->player.dir_y, speed);
	rotate(&cub->plane.x, &cub->plane.y, speed);
}

void	ft_key_hook(mlx_key_data_t keydata, void* param)
{
	t_cub	*cub;
	keys_t	key;

	cub = (t_cub *)param;
	key = keydata.key;
	if (key == MLX_KEY_LEFT)
		player_plane_rotation(cub, COUNTERCLOCKWISE);
	else if (key == MLX_KEY_RIGHT)
		player_plane_rotation(cub, CLOCKWISE);
	if (key == MLX_KEY_W || key == MLX_KEY_A || key == MLX_KEY_S
		|| key == MLX_KEY_D)
		wasd(cub, key);
	render(cub);
}