/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 00:51:12 by vde-frei          #+#    #+#             */
/*   Updated: 2024/03/30 00:58:46 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_time(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	//
	// // if (mlx_get_time() > cub->delay)
	if (1 < 2)
		cub->render_on = false;
}
