/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:40:49 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/15 15:11:29 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	minimap(&cub);
	mlx_terminate(cub.mlx);
	return (0);
}
