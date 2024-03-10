/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:28:53 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/10 16:13:06 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "import.h"

void	import(int argc, char *argv[], t_level *lvl)
{
	int	fd;

	fd = basic_validation(argc, argv);
	get_elements(fd, lvl);
	close(fd);
}
