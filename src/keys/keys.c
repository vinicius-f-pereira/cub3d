/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:31:06 by vde-frei          #+#    #+#             */
/*   Updated: 2024/03/24 19:59:58 by vde-frei         ###   ########.fr       */
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
