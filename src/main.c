/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:40:49 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/10 16:15:46 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	static t_level	lvl;

	import(argc, argv, &lvl);
	printf("R: %d G: %d B: %d\n", (int)lvl.f[0], (int)lvl.f[1], (int)lvl.f[2]);
	printf("R: %d G: %d B: %d\n", (int)lvl.c[0], (int)lvl.c[1], (int)lvl.c[2]);
	return (0);
}
