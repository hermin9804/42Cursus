/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:42:32 by mher              #+#    #+#             */
/*   Updated: 2022/06/04 23:59:29 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utiles.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_get_num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*ret;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = ft_get_num_len(n);
	ret = (char *)ft_malloc(sizeof(char), (len + 1));
	ret[len--] = 0;
	while (len >= 0)
	{
		ret[len--] = ft_abs(n % 10) + '0';
		n = ft_abs(n / 10);
	}
	if (sign == -1)
		ret[0] = '-';
	return (ret);
}
