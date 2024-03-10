/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:11:59 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/10 16:25:07 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "import.h"

static void	free_line_error(char *line, const char *error_msg,
	const int error_code)
{
	free(line);
	if (error_msg)
		exit_error_message(error_msg, error_code);
	exit (error_code);
}

static int	get_rgb(unsigned char dest[3], const char *str)
{
	int		index;
	int		i;

	if (!fill_valid_rgb_number(str, dest))
		return (error_message("Bad RGB specification"));
	i = -1;
	index = 0;
	while (str[++i] && str[i] != '\n')
	{
		if (ft_isdigit(str[i]) || ft_isspace(str[i]))
			continue ;
		if (str[i] == ',' && ++index)
		{
			if (index > 2)
				return (error_message("Bad RGB specification"));
			if (!fill_valid_rgb_number(str + i + 1, dest + index))
				return (error_message("Bad RGB specification"));
			continue ;
		}
		return (error_message("Bad RGB specification"));
	}
	if (index == 2)
		return (1);
	return (error_message("Bad RGB specification"));
}

static int	copy_element(int index, t_level *lvl, const char *str)
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
		return (get_rgb(lvl->f, str));
	else if (index == C)
		return (get_rgb(lvl->c, str));
	return (1);
}

static void	get_element(char *line, t_level *lvl, int *gotten_elements)
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
				free_line_error(line, "Repeated element", 6);
			if (!copy_element(index, lvl, line + j))
				free_line_error(line, NULL, 7);
			*gotten_elements |= index;
			return ;
		}
	}
	free_line_error(line, "Invalid or missing element", 8);
}

void	get_elements(int fd, t_level *lvl)
{
	char	*line;
	int		gotten_elements;

	gotten_elements = 0;
	while (gotten_elements != E_ALL)
	{
		line = get_next_line(fd);
		if (!line)
			exit_error_message("Missing elements", 4);
		if (ft_strlen(line) > MAX_COLS)
			free_line_error(line, "MAX_COLS exceeded", 5);
		if (*line != '\n')
			get_element(line, lvl, &gotten_elements);
		free (line);
	}
}
