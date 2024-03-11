/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:38:52 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/11 01:16:54 by brmoretti        ###   ########.fr       */
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

# define MAX_ROWS 100
# define MAX_COLS 80

typedef struct s_level
{
	char			no[MAX_COLS + 1];
	char			so[MAX_COLS + 1];
	char			we[MAX_COLS + 1];
	char			ea[MAX_COLS + 1];
	unsigned char	f[3];
	unsigned char	c[3];
	char			map[MAX_ROWS + 1][MAX_COLS + 1];
}	t_level;

void	import(int argc, char *argv[], t_level *lvl);

//DEBUG
void	print_cub_import(t_level *lvl);

#endif
