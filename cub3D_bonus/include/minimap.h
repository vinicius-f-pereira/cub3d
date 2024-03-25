/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:11:23 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/25 13:43:45 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

# define MINI_WIDTH 200
# define MINI_HEIGHT 150
# define MINI_X 10
# define MINI_Y 10
# define BORDER 0.05
# define WALL_COLOR 0xffffffc8
# define FLOOR_COLOR 0x00000064
# define PLAYER_COLOR 0x006437c8

void	draw_map(t_cub *cub);

#endif
