/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:38:52 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/20 13:45:07 by bmoretti         ###   ########.fr       */
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

//raycasting
# define N_RAYS 3

//MLX definitions
# define WIDTH 800
# define HEIGHT 600

//COLORS
# define BLACK 0x000000ff
# define WHITE 0xffffffff
# define RED 0xff0000ff
# define GREEN 0x00ff00ff
# define BLUE 0x0000ffff

# define M_PI 3.14159265358979323846
# define FOV 1.0

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

typedef struct s_ray
{
	int		index;
	double	dir_x;
	double	dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	len;
}	t_ray;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	t_ray	*rays[N_RAYS];
}	t_player;

typedef struct s_plane
{
	double	x;
	double	y;
}	t_plane;


typedef struct s_cub
{
	mlx_t		*mlx;
	t_level		level;
	t_minimap	mini;
	t_player	player;
	t_plane		plane;
}	t_cub;

void	import(int argc, char *argv[], t_level *lvl);
void	minimap(t_cub *cub);
void	raycasting(t_cub *cub);

//DEBUG
void	print_cub_import(t_level *lvl);

#endif
