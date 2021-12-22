/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:44:20 by mher              #+#    #+#             */
/*   Updated: 2021/12/21 12:05:22 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr_int(int nbr, t_info *info)
{
	int	tmp1 = 0;
	int	tmp2 = 0;
	int	tmp3 = 0;

	if (nbr < 0)
		info->nbr_sign = -1;
	if (info->minus == 1)
	{
		if (info->precision != -1)
		{
			tmp1 = put_precision_width(ft_numlen(nbr), info->precision, info);
			if (tmp1 == -1)
				return (ERROR);
			tmp2 = ft_putnbr(nbr);
			if (tmp2 == -1)
				return (ERROR);
			tmp3 = put_width_nbr_flags(0, info->precision, info);
			if (tmp3 == -1)
				return (ERROR);
		}
		if (info->precision == -1)
		{
			if (info->nbr_sign == -1)
			{
				tmp1 = write(1, "-", 1);
				if (tmp1 == -1)
					return (ERROR);
			}
			tmp2 = ft_putnbr(nbr);
			if (tmp2 == -1)
				return (ERROR);
			tmp3 = put_width_nbr_flags(ft_numlen(nbr), info->width, info);
			if (tmp3 == -1)
				return (ERROR);
		}
	}
	else
	{
		if (info->precision != -1)
		{
			tmp1 = put_width_nbr_flags(info->precision, info->width, info);
			if (tmp1 == -1)
				return (ERROR);
			tmp2 = put_precision_width(ft_numlen(nbr), info->precision, info);
			if (tmp2 == -1)
				return (ERROR);
			tmp3 = ft_putnbr(nbr);
			if (tmp3 == -1)
				return (ERROR);
		}
		if (info->precision == -1)
		{
			if (info->nbr_sign == -1 && info->zero == 0 && info->width == 0)
			{
				tmp1 = write(1, "-", 1);
				if (tmp1 == -1)
					return (ERROR);
			}
			tmp2 = put_width_nbr_flags(ft_numlen(nbr), info->width, info);
			if (tmp2 == -1)
				return (ERROR);
			if (info->nbr_sign == -1 && info->zero == 0 && info->width != 0)
			{
				tmp1 = write(1, "-", 1);
				if (tmp1 == -1)
					return (ERROR);
			}
			tmp3 = ft_putnbr(nbr);
			if (tmp3 == -1)
				return (ERROR);
		}
	}
	return (tmp1 + tmp2 + tmp3);
}

int	put_width_nbr_flags(int start, int end, t_info *info)
{
	int		ret;
	char		width_char;

	ret = 0;
	width_char = ' ';
	if (info->zero == 1 && info->precision == -1)
		width_char = '0';
	if (info->nbr_sign == -1 && info->precision == -1 && info->zero == 1)
	{
		ret += 1;
		if (write(1, "-", 1) == -1)
			return (ERROR);
	}
	while (start++ < end + info->nbr_sign)
	{
		if (write(1, &width_char, 1) == -1)
			return (ERROR);
		++ret;
	}
	if (info->nbr_sign == -1 && info->precision != -1 && info->minus == 0)
	{
		ret += 1;
		if (write(1, "-", 1) == -1)
			return (ERROR);
	}
	return (ret);
}

int	put_precision_width(int start, int end, t_info *info)
{
	int		ret;
	char	width_char;

	ret = 0;
	width_char = '0';
	if (info->nbr_sign == -1 && info->width != 0 && info->precision != -1 && info->minus == 1)
	{
		ret += 1;
		if (write(1, "-", 1) == -1)
			return (ERROR);
	}
	while (start++ < end)
	{
		if (write(1, &width_char, 1) == -1)
			return (ERROR);
		++ret;
	}
	return (ret);
}

void	ft_print_nbr(int n, int *len)
{
	*len += 1;
	if (n > 9)
		ft_print_nbr(n / 10, len);
	write(1, &"0123456789"[n % 10], 1);
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
