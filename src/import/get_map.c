/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:08:39 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/12 13:39:32 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "import.h"

static int	line_break(t_import_elements *lvl_el, int *valid_lines)
{
	if (*lvl_el->line == '\n')
	{
		if (*valid_lines)
			get_elements_error(lvl_el, "Map with blank row", 21);
		free (lvl_el->line);
		lvl_el->line = get_next_line(lvl_el->fd);
		return (1);
	}
	return (0);
}

static void	get_line_len(const char *line, size_t *len)
{
	*len = ft_strlen(line);
	if (line[*len - 1] == '\n')
		(*len)--;
}

void	get_map(t_import_elements *lvl_el)
{
	int		valid_lines;
	size_t	len;

	lvl_el->line = get_next_line(lvl_el->fd);
	valid_lines = 0;
	while (lvl_el->line)
	{
		if (line_break(lvl_el, &valid_lines))
			continue ;
		get_line_len(lvl_el->line, &len);
		if (len > MAX_COLS)
			get_elements_error(lvl_el, "Map MAX_COLS exceeded", 23);
		if (++valid_lines > MAX_ROWS)
			get_elements_error(lvl_el, "Map MAX_ROWS exceeded", 22);
		ft_memcpy(lvl_el->lvl->map[valid_lines - 1], lvl_el->line, len);
		free (lvl_el->line);
		lvl_el->line = get_next_line(lvl_el->fd);
	}
	if (!valid_lines)
		get_elements_error(lvl_el, "Map missing", 20);
}
