/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:29:08 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/10 16:13:47 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPORT_H
# define IMPORT_H

# include "cub3d.h"

enum e_elements
{
	NO = 1,
	SO = 2,
	WE = 4,
	EA = 8,
	F = 16,
	C = 32,
	E_ALL = 63
};

int		basic_validation(int argc, char *argv[]);
int		error_message(const char *error_msg);
void	exit_error_message(const char *error_msg, const int error_code);
void	get_elements(int fd, t_level *lvl);
int		fill_valid_rgb_number(const char *str, unsigned char *dest);

#endif
