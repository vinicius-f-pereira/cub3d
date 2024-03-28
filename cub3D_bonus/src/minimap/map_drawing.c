/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:06:13 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/25 17:32:10 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	draw_player(t_cub *cub)
{
	int			x;
	int			y;
	const int	map_x = (int)cub->player.pos_x;
	const int	map_y = (int)cub->player.pos_y;
	const int	half_player = cub->mini.side / 4;

	x = map_x * (cub->mini.border + cub->mini.side) + MINI_X;
	x += (int)((cub->player.pos_x - (double)map_x) * (double)cub->mini.side);
	x -= half_player;
	y = map_y * (cub->mini.border + cub->mini.side) + MINI_Y;
	y += (int)((cub->player.pos_y - (double)map_y) * (double)cub->mini.side);
	y -= half_player;
	mlx_image_to_window(cub->mlx, cub->mini.player, x, y);
}

void	draw_map(t_cub *cub)
{
	int		i;
	int		j;
	int		pos[2];
	char	c;

	i = -1;
	while (cub->level.map[++i][0])
	{
		j = -1;
		while (cub->level.map[i][++j])
		{
			c = cub->level.map[i][j];
			pos[0] = j * (cub->mini.border + cub->mini.side) + MINI_X;
			pos[1] = i * (cub->mini.border + cub->mini.side) + MINI_Y;
			if (c == '1' && mlx_image_to_window(cub->mlx,
					cub->mini.wall, pos[0], pos[1]) < 0)
				exit (42);
			else if (ft_strchr("0NSEW", c)
				&& mlx_image_to_window(cub->mlx,
					cub->mini.floor, pos[0], pos[1]) < 0)
				exit (42);
			draw_player(cub);
		}
	}
}
