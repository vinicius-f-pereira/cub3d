/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:11:23 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/18 17:22:36 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

# define MINI_WIDTH 700
# define MINI_HEIGHT 500
# define MINI_X 10
# define MINI_Y 10
# define BORDER 0.05

void	draw_map(t_cub *cub);

#endif
