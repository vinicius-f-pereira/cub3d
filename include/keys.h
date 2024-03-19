/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:16:07 by vde-frei          #+#    #+#             */
/*   Updated: 2024/03/19 10:29:07 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include "cub3d.h"

void	ft_end_key(mlx_key_data_t key, t_cub *cub);
void	ft_move(mlx_key_data_t key, t_cub *cub);
void	ft_keys(mlx_key_data_t key, void *cub);

#endif // !KEYS_H
