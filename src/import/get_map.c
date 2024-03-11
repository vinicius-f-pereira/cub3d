/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:08:39 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/11 00:52:15 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "import.h"

void	get_map(t_import_elements *lvl_el)
{
	int	valid_lines;

	lvl_el->line = get_next_line(lvl_el->fd);
	if (!lvl_el->line)
		get_elements_error(lvl_el, "Map missing", 20);
	valid_lines = 0;
	while (lvl_el->line)
	{
		if (*lvl_el->line == '\n')
		{
			if (valid_lines)
				get_elements_error(lvl_el, "Map with blank row", 21);
			free (lvl_el->line);
			lvl_el->line = get_next_line(lvl_el->fd);
			continue ;
		}
		if (ft_strlen(lvl_el->line) > MAX_COLS)
			get_elements_error(lvl_el, "Map MAX_COLS exceeded", 23);
		if (++valid_lines > MAX_ROWS)
			get_elements_error(lvl_el, "Map MAX_ROWS exceeded", 22);
		ft_memcpy(lvl_el->lvl->map[valid_lines - 1], lvl_el->line,
			ft_strlen(lvl_el->line) - 1);
		free (lvl_el->line);
		lvl_el->line = get_next_line(lvl_el->fd);
	}
}
