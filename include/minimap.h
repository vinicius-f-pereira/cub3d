/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:11:23 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/15 21:53:44 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

# define MINI_WIDTH 700
# define MINI_HEGHT 500
# define MINI_X 10
# define MINI_Y 10
# define BORDER 0.05

void	draw_map(t_cub *cub);

#endif
