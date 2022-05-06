/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:16:51 by mher              #+#    #+#             */
/*   Updated: 2022/05/06 16:32:08 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_exit(const char *error_msg, int exit_code)
{
	perror(error_msg);
	exit(exit_code);
}

void	error_exit(const char *error_msg, int exit_code)
{
	size_t	len;

	len = ft_strlen(error_msg);
	if (len > 0)
	{
		handle_error_write(STDERR_FILENO, error_msg, len);
		handle_error_write(STDERR_FILENO, "\n", 1);
	}
	exit(exit_code);
}
