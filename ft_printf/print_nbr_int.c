/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:44:20 by mher              #+#    #+#             */
/*   Updated: 2021/12/20 21:03:57 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr_int(int nbr, t_info *info)
{
	int tmp1;
	int tmp2;
	int tmp3;

	if (nbr < 0)
		info->nbr_sign = -1;
	if (info->minus == 1)
	{
		tmp1 = put_precision_width(nbr, info);
		if (tmp1 == -1)
			return (ERROR);
		tmp2 = ft_putnbr(nbr);
		if (tmp2 == -1)
			return (ERROR);
		tmp3 = put_width_nbr_flags(nbr, info);
		if (tmp3 == -1)
			return (ERROR);
	}
	else
	{
		tmp1 = put_width_nbr_flags(nbr, info);
		if (tmp1 == -1)
			return (ERROR);
		tmp2 = put_precision_width(nbr, info);
		if (tmp2 == -1)
			return (ERROR);
		tmp3 = ft_putnbr(nbr);
		if (tmp3 == -1)
			return (ERROR);
	}
	return (tmp1 + tmp2 + tmp3);
}

int	put_width_nbr_flags(int nbr, t_info *info)
{
	int		ret;
	char	width_char;
	int		num_len;

	ret = 0;
	width_char = ' ';
	if (info->zero == 1)
		width_char = '0';
	if (nbr < 0)
		info->nbr_sign = -1;
	num_len = ft_numlen(nbr);
	while (num_len++ < info->width - info->precision)
	{
		if (write(1, &width_char, 1) == -1)
			return (ERROR);
		++ret;
	}
	return (ret);
}

int	put_precision_width(int nbr, t_info *info)
{
	int		ret;
	char	width_char;
	int		num_len;

	ret = 0;
	width_char = '0';
	num_len = ft_numlen(nbr);
	while (num_len++ < info->precision)
	{
		if (write(1, &width_char, 1) == -1)
			return (ERROR);
		++ret;
	}
	return (ret);
}

void	ft_print_nbr(int n, int *len)
{
	if (n > 9)
		ft_print_nbr(n / 10, len);
	write(1, &"0123456789"[n % 10], 1);
	*len += 1;
}

int	ft_putnbr(int n)
{
	int len;

	len = 0;
	if (n == -2147483648)
		return (write(1, "2147483648", 10));
	if (n < 0)
		n *= -1;
	ft_print_nbr(n, &len);
	return (len);
}
