/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:31:06 by vde-frei          #+#    #+#             */
/*   Updated: 2024/03/19 10:32:34 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "keys.h"

void	ft_end_key(mlx_key_data_t key, t_cub *cub)
{
	if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(cub->mlx);
		return;
	}
}

void	ft_move(mlx_key_data_t key, t_cub *cub)
{
	if (key.key == MLX_KEY_D)
		cub->mini.player->instances[0].x += cub->mini.side / 10;
	if (key.key == MLX_KEY_A)
		cub->mini.player->instances[0].x -= cub->mini.side / 10;
	if (key.key == MLX_KEY_W)
		cub->mini.player->instances[0].y -= cub->mini.side / 10;
	if (key.key == MLX_KEY_S)
		cub->mini.player->instances[0].y += cub->mini.side / 10;
	if (key.key == MLX_KEY_Z)
		cub->mini.player->instances[0].z++;
	if (key.key == MLX_KEY_X)
		cub->mini.player->instances[0].z--;
}

void	ft_keys(mlx_key_data_t key, void *cub)
{
	t_cub	*_cub;

	_cub = (t_cub *)cub;
	ft_move(key, _cub);
	ft_end_key(key, _cub);
}
