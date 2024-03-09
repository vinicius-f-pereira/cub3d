/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:11:59 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/08 19:36:08 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "import.h"

int	which_element(short int index, t_level *lvl)
{
	if (index == 0)

}

int	get_element(char *line, t_level *lvl)
{
	const char	*elements[] = {"NO ", "SO ", "WE ", "EA ", "F ", "C ", NULL};
	short int	i;
	size_t		j;

	i = -1;
	while (elements[++i])
	{
		j = ft_strlen(elements[i]);
		if (!ft_strncmp(elements[i], line, j))
			{
				while (!ft_isspace(line[j]))
					j++;
				if (i == 0)
					ft_memcpy(lvl->no, line[j], ft_strlen(line[j - 1]));
				else if (i == 1)

			}
	}
}

int	get_elements(int fd, t_level *lvl)
{
	char	*line;
	int		is_map;

	line = get_next_line(fd);
	is_map = 0;
	while (line)
	{
		if (ft_strlen(line) > MAX_COLS)
		{
			printf("The file can't have more than %d cols\n", MAX_COLS);
			free (line);
			return (0);
		}
		get_element
	}
}
