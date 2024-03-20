/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:40:49 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/20 11:35:31 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d.h"
#include "keys.h"


int	main(int argc, char *argv[])
{
	static t_cub	cub;

	import(argc, argv, &cub.level);
#ifdef DEBUG
	printf("Import success\n");
#endif
	raycasting(&cub);
	cub.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	mlx_key_hook(cub.mlx, ft_keys, &cub);
	minimap(&cub);
	mlx_terminate(cub.mlx);
	return (0);
}
