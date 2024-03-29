/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 08:51:22 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/29 08:52:36 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
