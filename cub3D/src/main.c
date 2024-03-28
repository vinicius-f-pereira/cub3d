/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:40:49 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/28 14:27:59 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "cub3d.h"

void	free_texture(t_cub *cub)
{
	int	i;

	i = -1;
	mlx_delete_texture(cub->render->no);
	mlx_delete_texture(cub->render->so);
	mlx_delete_texture(cub->render->ea);
	mlx_delete_texture(cub->render->we);
	while (++i < N_RAYS)
	{
		mlx_delete_image(cub->mlx, cub->render->boxes[i]);
	}
	render_destroy(cub);
}

int	main(int argc, char *argv[])
{
	static t_cub	cub;

	import(argc, argv, &cub.level);
#ifdef DEBUG
	printf("Import success\n");
#endif
	cub.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d", true);
	render_init(&cub);
	render(&cub);
	mlx_key_hook(cub.mlx, ft_key_hook, &cub);
	mlx_loop(cub.mlx);
	mlx_terminate(cub.mlx);
	free_texture(&cub);
	return (0);
}
