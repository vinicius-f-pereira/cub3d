/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:40:49 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/18 19:00:24 by vde-frei         ###   ########.fr       */
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
	cub.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", 0);
	if (!cub.mlx)
		exit (EXIT_FAILURE);
	mlx_key_hook(cub.mlx, (mlx_keyfunc)ft_end_key, &cub);
	minimap(&cub);
	mlx_terminate(cub.mlx);
	return (0);
}
