/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations_bkp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:48:25 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/12 14:49:11 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "import.h"

static void	check_wall(t_level *lvl, int start[2], int i_step, int j_step)
{
	start[0] += i_step;
	start[1] += j_step;
	while (start[0] > -1 && start[1] > -1 && lvl->map[start[0]][start[1]]
		&& lvl->map[start[0]][start[1]] != ' ')
	{
		if (lvl->map[start[0]][start[1]] == '1')
			return ;
		start[0] += i_step;
		start[1] += j_step;
	}
	exit_error_message("🎵 We don't need no education...\n"
		"🧱 Missing another brick in the wall\n", 33);
}

static void	walls_around(t_level *lvl, int i, int j)
{
	int	start[2];

	if (ft_strchr(" 1", lvl->map[i][j]))
		return ;
	start[0] = i;
	start[1] = j;
	check_wall(lvl, start, -1, 0);
	check_wall(lvl, start, 1, 0);
	check_wall(lvl, start, 0, -1);
	check_wall(lvl, start, 0, 1);
}

static void	valid_char(const char c, int *count_player)
{
	const char	valids[4] = " z1";
	const char	player[5] = "NSEW";

	if (ft_strchr(valids, c))
		return ;
	if (!ft_strchr(player, c))
		exit_error_message("Bad map charachter", 34);
	(*count_player)++;
	if (*count_player > 1)
		exit_error_message("Only one player allowed in the map", 30);
}

static int	zero_flood_fill(t_level *lvl, int i, int j)
{
	const char	c = lvl->map[i][j];

	if (i < 0 || j < 0 || !c || c == '.')
		return (0);
	if (c == '0')
		lvl->map[i][j] = '.';
	else if (!ft_strchr("NSEW", c))
		return (0);
	zero_flood_fill(lvl, i - 1, j);
	zero_flood_fill(lvl, i + 1, j);
	zero_flood_fill(lvl, i, j - 1);
	zero_flood_fill(lvl, i, j + 1);
	return (1);
}

void	map_validation(t_level *lvl)
{
	int	i;
	int	j;
	int	count_player;
	int	contiguous;

	contiguous = 0;
	count_player = 0;
	i = -1;
	while (++i < MAX_ROWS && lvl->map[i][0])
	{
		j = -1;
		while (++j < MAX_COLS && lvl->map[i][j])
		{
			contiguous += zero_flood_fill(lvl, i, j);
			if (contiguous > 1)
			{
				print_cub_import(lvl);
				exit_error_message("The map must be contiguous", 31);
			}
			valid_char(lvl->map[i][j], &count_player);
			walls_around(lvl, i, j);
		}
	}
	if (!count_player)
		exit_error_message("One player needed in the map", 32);
}
