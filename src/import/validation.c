/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:12 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/08 15:23:47 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "import.h"

int	basic_validation(int argc, char *argv[])
{
	size_t	len;
	int		fd;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./cub3d <file_path.cub>", 2);
		return (0);
	}
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_strncmp(argv[1][len - 4], ".cub", 4))
	{
		ft_putendl_fd("The map must be a valid .cub file", 2);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_putendl_fd(strerror(errno), 2);
	return (1);
}
