/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:12 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/10 02:24:05 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "import.h"

int	basic_validation(int argc, char *argv[])
{
	size_t	len;
	int		fd;

	if (argc != 2)
		return (error_message("Usage: ./cub3d <map_file.cub>"));
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_strncmp(argv[1] + len - 4, ".cub", 4))
		return (error_message("Expected a .cub file"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (error_message(strerror(errno)));
	return (fd);
}

int	valid_rgb_number(const char *str)
{
	size_t	i;
	size_t	zeros;
	int		number;

	zeros = 0;
	while (str[zeros] == '0')
		zeros++;
	i = 0;
	while (ft_isdigit(str[zeros + i]))
		i++;
	if (i + zeros == 0 || i > 3)
		return (-1);
	number = ft_atoi(str);
	if (0 <= number || number <= 255)
		return (number);
	return (-1);
}
