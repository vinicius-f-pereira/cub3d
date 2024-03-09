/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:38:52 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/08 15:15:15 by bmoretti         ###   ########.fr       */
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
	char	no[MAX_COLS + 1];
	char	so[MAX_COLS + 1];
	char	we[MAX_COLS + 1];
	char	ea[MAX_COLS + 1];
	char	f[MAX_COLS + 1];
	char	c[MAX_COLS + 1];
	char	map[MAX_ROWS + 1][MAX_COLS + 1];
}	t_level;

int	import(int argc, char *argv[], t_level *lvl);

#endif
