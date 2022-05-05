/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:16:51 by mher              #+#    #+#             */
/*   Updated: 2022/05/05 17:44:33 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_exit(char *error_msg)
{
	perror(error_msg);
	exit(EXIT_FAILURE);
}

void	error_exit(char *error_msg)
{
	size_t len;

	len = ft_strlen(error_msg);
	if (len > 0)
		write(STDERR_FILENO, error_msg, len);
	exit(EXIT_FAILURE);
}
