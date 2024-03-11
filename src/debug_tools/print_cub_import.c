/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cub_import.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 01:06:31 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/11 01:29:50 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_cub_import(t_level *lvl)
{
	int	r;
	int	g;
	int b;
	int	i;
	
	printf("NO: %s\n", lvl->no);
	printf("SO: %s\n", lvl->so);
	printf("EA: %s\n", lvl->ea);
	printf("WE: %s\n", lvl->we);
	r = (int)lvl->f[0];
	g = (int)lvl->f[1];
	b = (int)lvl->f[2];
	printf("F:  %-3d %-3d %-3d\n", r, g, b);
	r = (int)lvl->c[0];
	g = (int)lvl->c[1];
	b = (int)lvl->c[2];
	printf("C:  %-3d %-3d %-3d\n", r, g, b);
	printf("\nMAP:\n");
	i = -1;
	while (lvl->map[++i][0])
		printf("%s\n", lvl->map[i]);
}
