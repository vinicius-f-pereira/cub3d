/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:05:49 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/22 14:25:24 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	set_initial_player_pos(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub->level.map[++i][0])
	{
		j = -1;
		while (cub->level.map[i][++j])
		{
			if (ft_strchr("NSEW", cub->level.map[i][j]))
			{
				cub->player.pos_y = (double)i + 0.5;
				cub->player.pos_x = (double)j + 0.5;
				if (cub->level.map[i][j] == 'E')
					cub->player.dir_x = 1;
				else if (cub->level.map[i][j] == 'N')
					cub->player.dir_y = -1;
				else if (cub->level.map[i][j] == 'W')
					cub->player.dir_x = -1;
				else if (cub->level.map[i][j] == 'S')
					cub->player.dir_y = 1;
				return ;
			}
		}
	}
}

void	set_initial_plane(t_cub	*cub)
{
	cub->plane.x = cub->player.dir_x;
	cub->plane.y = cub->player.dir_y;
	rotate(&cub->plane.x, &cub->plane.y, M_PI / 2);
	cub->plane.x *= FOV;
	cub->plane.y *= FOV;
}

void	render_destroy(t_cub *cub)
{
	mlx_delete_image(cub->mlx, cub->render->ceiling);
	mlx_delete_image(cub->mlx, cub->render->floor);
	free (cub->render);
}

void	render_init(t_cub *cub)
{
	uint32_t	color;
	uint32_t	heights;

	cub->render = malloc(sizeof(t_render));
	if (!cub->render)
		exit (EXIT_FAILURE);
	cub->render->width = WINDOW_WIDTH / N_RAYS;
	heights = WINDOW_HEIGHT / 2;
	cub->render->ceiling = mlx_new_image(cub->mlx, WINDOW_WIDTH, heights);
	color = color_rgba(cub->level.c[0], cub->level.c[1], cub->level.c[2], 255);
	rectangle_fill(cub->render->ceiling, color);
	mlx_image_to_window(cub->mlx, cub->render->ceiling, 0, 0);
	cub->render->floor = mlx_new_image(cub->mlx, WINDOW_WIDTH, heights);
	color = color_rgba(cub->level.f[0], cub->level.f[1], cub->level.f[2], 255);
	rectangle_fill(cub->render->floor, color);
	mlx_image_to_window(cub->mlx, cub->render->floor, 0, WINDOW_HEIGHT / 2);
	set_initial_player_pos(cub);
	set_initial_plane(cub);
}
