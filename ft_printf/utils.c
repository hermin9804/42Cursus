/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:15:58 by mher              #+#    #+#             */
/*   Updated: 2021/12/18 17:16:40 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(int num)
{
	int len;

	len = 0;
	while (num)
	{
		++len;
		num /= 10;
	}
	return(len);
}

int	ft_putchar(char c, int *total_len)
{
	*total_len += 1;
	return (write(1, &c, 1));
}
