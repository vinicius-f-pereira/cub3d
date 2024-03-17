/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:38:52 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/17 13:00:26 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <string.h>

# include "libft.h"
# include "MLX42.h"

//.cub files definitions
# define MAX_ROWS 100
# define MAX_COLS 80

//MLX definitions
# define WIDTH 800
# define HEIGHT 600

//COLORS
# define BLACK 0x000000ff
# define WHITE 0xffffffff
# define RED 0xff0000ff
# define GREEN 0x00ff00ff
# define BLUE 0x0000ffff

typedef struct s_level
{
	char			no[MAX_COLS + 1];
	char			so[MAX_COLS + 1];
	char			we[MAX_COLS + 1];
	char			ea[MAX_COLS + 1];
	unsigned char	f[3];
	unsigned char	c[3];
	char			map[MAX_ROWS + 1][MAX_COLS + 1];
	size_t			x_size;
	size_t			y_size;
}	t_level;

typedef struct s_minimap
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	int			side;
	int			border;
}	t_minimap;

typedef struct s_cub
{
	mlx_t		*mlx;
	t_level		level;
	t_minimap	mini;
}	t_cub;

void	import(int argc, char *argv[], t_level *lvl);
void	minimap(t_cub *cub);

//DEBUG
void	print_cub_import(t_level *lvl);

#endif
