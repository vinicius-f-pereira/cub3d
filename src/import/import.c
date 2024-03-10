/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:28:53 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/10 03:14:22 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "import.h"

int	import(int argc, char *argv[], t_level *lvl)
{
	int	fd;

	fd = basic_validation(argc, argv);
	if (fd <= 0)
		return (0);
	if (!get_elements(fd, lvl))
		return (0);
	close(fd);
	return (1);
}
