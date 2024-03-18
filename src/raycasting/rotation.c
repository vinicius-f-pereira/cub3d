/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:17:17 by brmoretti         #+#    #+#             */
/*   Updated: 2024/03/18 10:12:24 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	rotate(double *x, double *y, double rad)
{
	double	x_temp;
	double	y_temp;

	x_temp = *x;
	y_temp = *y;
	*x = x_temp * cos(rad) + y_temp * sin(rad);
	*y = x_temp * -sin(rad) + y_temp * cos(rad);
}
