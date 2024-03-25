/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:28:53 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/12 14:29:11 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "import.h"

void	import(int argc, char *argv[], t_level *lvl)
{
	t_import_elements	lvl_el;

	lvl_el.fd = basic_validation(argc, argv);
	lvl_el.lvl = lvl;
	lvl_el.line = NULL;
	get_elements(&lvl_el);
	get_map(&lvl_el);
#ifdef DEBUG
	print_cub_import(lvl);
#endif
	map_validation(lvl);
	close(lvl_el.fd);
}
