/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:08:39 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/10 18:58:35 by bmoretti         ###   ########.fr       */
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
				get_elements_error(lvl_el, "No blank lines in the map allowed", 21);
			free (lvl_el->line);
			get_next_line(lvl_el->fd);
			continue ;
		}
		valid_lines++;
		lvl_el->line = get_next_line(lvl_el->fd);
		if (!lvl_el->line)
			get_elements_error(lvl_el, "Missing elements", 4);
		if (ft_strlen(lvl_el->line) > MAX_COLS)
			get_elements_error(lvl_el, "MAX_COLS exceeded", 5);
		if (*lvl_el->line != '\n')
			get_element(lvl_el, &gotten_elements);
		free (lvl_el->line);
	}
}
