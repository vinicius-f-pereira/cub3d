/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:46:34 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/10 16:06:36 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "import.h"

int	error_message(const char *error_msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd((char *)error_msg, STDERR_FILENO);
	return (0);
}

void	exit_error_message(const char *error_msg, const int error_code)
{
	error_message(error_msg);
	exit (error_code);
}
