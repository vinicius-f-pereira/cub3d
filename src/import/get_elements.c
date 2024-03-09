/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:11:59 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/09 16:24:02 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "import.h"

enum e_elements
{
	NO = 1,
	SO = 2,
	WE = 4,
	EA = 8,
	F = 16,
	C = 32
};

void	copy_element(int index, t_level *lvl, const char *str)
{
	if (index == NO)
		ft_memcpy(lvl->no, str, ft_strlen(str) - 1);
	else if (index == SO)
		ft_memcpy(lvl->so, str, ft_strlen(str) - 1);
	else if (index == WE)
		ft_memcpy(lvl->we, str, ft_strlen(str) - 1);
	else if (index == EA)
		ft_memcpy(lvl->ea, str, ft_strlen(str) - 1);
	else if (index == F)
		ft_memcpy(lvl->f, str, ft_strlen(str) - 1);
	else if (index == C)
		ft_memcpy(lvl->c, str, ft_strlen(str) - 1);
}

int	get_element(char *line, t_level *lvl, int *gotten_elements)
{
	const char	*elements[] = {"NO ", "SO ", "WE ", "EA ", "F ", "C ", NULL};
	short int	i;
	size_t		j;
	int			index;

	i = -1;
	while (elements[++i])
	{
		j = ft_strlen(elements[i]);
		if (!ft_strncmp(elements[i], line, j))
		{
			while (!ft_isspace(line[j]))
				j++;
			index = (int)pow(2.0, (double)i);
			if (*gotten_elements & index)
			{
				ft_putendl_fd("Repeated element", 2);
				return (0);
			}
			copy_element(index, lvl, line[j]);
			*gotten_elements |= index;
			return (1);
		}
	}
	return (0);
}

int	free_line_error(char *line, const char *error_msg)
{
	free(line);
	return (error_message(error_msg));
}

int	get_elements(int fd, t_level *lvl)
{
	char	*line;
	int		is_map;
	int		gotten_elements;

	is_map = 0;
	gotten_elements = 0;
	while (gotten_elements != E_ALL)
	{
		line = get_next_line(fd);
		if (!line)
			return (error_message("Missing elements"));
		if (ft_strlen(line) > MAX_COLS)
			return (free_line_error(line, "MAX_COLS exceeded"));
		if (*line != '\0')
		{
			if (!get_element(line, lvl, &gotten_elements))
				return (free_line_error(line, "Invalid element"));
		}
		free (line);
	}
	return (1);
}
