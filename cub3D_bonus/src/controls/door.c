/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:05:17 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/29 11:48:44 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	door_closing(t_cub *cub)
{
	const double time = mlx_get_time();
	int			i;
	int			j;
	const int	pos_x = (int)cub->player.pos_x;
	const int	pos_y = (int)cub->player.pos_y;

	if ((int)cub->door_last_time == 0 || time < cub->door_last_time + 5.0)
		return;
	i = -1;
	while (cub->level.map[++i][0])
	{
		j = -1;
		while (cub->level.map[i][++j])
		{
			if (cub->level.map[i][j] == 'd' && i != pos_y && j != pos_x)
			{
				cub->level.map[i][j] = 'D';
				cub->door_last_time = 0.0;
			}
		}
	}
}

void	door_opening(t_cub *cub)
{
	double	door_x;
	double	door_y;

	door_x = cub->player.pos_x + cub->player.dir_x;
	door_y = cub->player.pos_y + cub->player.dir_y;
	if (cub->level.map[(int)door_y][(int)door_x] == 'D')
		cub->level.map[(int)door_y][(int)door_x] = 'd';
	cub->door_last_time = mlx_get_time();
}