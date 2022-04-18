/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:31:04 by mher              #+#    #+#             */
/*   Updated: 2022/04/16 17:28:02 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"

void	error_exit(const char *msg)
{
	while (*msg)
		write(2, msg++, 1);
	exit(1);
}
