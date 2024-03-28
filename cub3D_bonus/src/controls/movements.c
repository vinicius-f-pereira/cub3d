/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:19:46 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/26 20:12:18 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d.h"
#include "keys.h"

void	mouse_follow(t_cub *cub);

static void	valid_new_pos(t_cub *cub, double dir_x, double dir_y)
{
	double	delta[2];
	int		map_pos[2];
	double	new_pos[2];

	delta[0] = LINEAR_SPEED * dir_x;
	delta[1] = LINEAR_SPEED * dir_y;
	map_pos[0] = (int)cub->player.pos_x;
	map_pos[1] = (int)cub->player.pos_y;
	new_pos[0] = cub->player.pos_x + delta[0] + dir_x * 0.10;
	if (cub->level.map[map_pos[1]][(int)new_pos[0]] == '0')
		cub->player.pos_x = cub->player.pos_x + delta[0];
	new_pos[1] = cub->player.pos_y + delta[1] + dir_y * 0.10;
	if (cub->level.map[(int)new_pos[1]][map_pos[0]] == '0')
		cub->player.pos_y = cub->player.pos_y + delta[1];
}

static void	wasd(t_cub *cub, keys_t key)
{
	double	dir_x;
	double	dir_y;

	mouse_follow(cub);
	dir_x = cub->player.dir_x;
	dir_y = cub->player.dir_y;
	if (key == MLX_KEY_A || key == MLX_KEY_D)
		rotate(&dir_x, &dir_y, M_PI / 2);
	if (key == MLX_KEY_S || key == MLX_KEY_A)
	{
		dir_x *= -1;
		dir_y *= -1;
	}
	valid_new_pos(cub, dir_x, dir_y);
	render(cub);
}

void	player_plane_rotation(t_cub *cub, int direction)
{
	double	speed;

	speed = (double)direction * ANGULAR_SPEED;
	rotate(&cub->player.dir_x, &cub->player.dir_y, speed);
	rotate(&cub->plane.x, &cub->plane.y, speed);
	render(cub);
}

void	ft_key_hook(mlx_key_data_t key, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	ft_end_key(key, cub);
	if (key.key == MLX_KEY_LEFT)
		player_plane_rotation(cub, COUNTERCLOCKWISE);
	else if (key.key == MLX_KEY_RIGHT)
		player_plane_rotation(cub, CLOCKWISE);
	if (key.key == MLX_KEY_W || key.key == MLX_KEY_A || key.key == MLX_KEY_S
		|| key.key == MLX_KEY_D)
		wasd(cub, key.key);
}

void	mouse_follow(t_cub *cub)
{
 	int32_t			pos[2];
	double			rotation;
	double			signal;

	mlx_get_mouse_pos(cub->mlx, &pos[0], &pos[1]);
	rotation = ((double)pos[0] - WINDOW_WIDTH / 2) / (WINDOW_WIDTH / 2);
	if (rotation < 0)
		signal = -1.0;
	else
		signal = 1.0;
	rotation *= rotation * signal / 10;
	rotate(&cub->player.dir_x, &cub->player.dir_y, rotation);
	rotate(&cub->plane.x, &cub->plane.y, rotation);
}