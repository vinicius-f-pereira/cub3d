/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:11:59 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/10 03:07:20 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "import.h"

int	get_rgb(unsigned char *dest, const char *str)
{
	int		numbers[3];
	int		index;
	int		i;

	numbers[0] = valid_rgb_number(str);
	i = -1;
	index = 0;
	while (str[++i] && str[i] != '\n')
	{
		if (ft_isdigit(str[i]))
			continue;
		if (str[i] == ',' && ++index)
		{
			if (index > 2)
				return (error_message("Bad RGB specification"));
			numbers[index] = valid_rgb_number(str + i + 1);
			continue;
		}
		return (error_message("Bad RGB specification"));
	}
	if (numbers[0] == -1 || numbers[1] == -1 || numbers[2] == -1)
		return (error_message("Bad RGB specification"));
	dest[0] = (unsigned char)numbers[0];
	dest[1] = (unsigned char)numbers[1];
	dest[2] = (unsigned char)numbers[2];
	return (1);
}

int	copy_element(int index, t_level *lvl, const char *str)
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
		return(get_rgb(lvl->f_rgb, str));
	else if (index == C)
		return(get_rgb(lvl->c_rgb, str));
	return (1);
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
			while (ft_isspace(line[j]))
				j++;
			index = 1 << i;
			if (*gotten_elements & index)
				return (error_message("Repeated element"));
			if (!copy_element(index, lvl, line + j))
				return (0);
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
	int		gotten_elements;

	gotten_elements = 0;
	while (gotten_elements != E_ALL)
	{
		line = get_next_line(fd);
		if (!line)
			return (error_message("Missing elements"));
		if (ft_strlen(line) > MAX_COLS)
			return (free_line_error(line, "MAX_COLS exceeded"));
		if (*line != '\n')
		{
			if (!get_element(line, lvl, &gotten_elements))
				return (free_line_error(line, "Invalid element"));
		}
		free (line);
	}
	return (1);
}
