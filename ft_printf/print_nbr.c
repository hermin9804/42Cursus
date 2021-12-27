/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:44:20 by mher              #+#    #+#             */
/*   Updated: 2021/12/27 17:49:01 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(unsigned long long nbr, t_info *info)
{
	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->nbr_base = 16;
	if ((info->type == 'd' || info->type == 'i') && (int)nbr < 0)
	{
		info->nbr_sign = -1;
		nbr *= -1;
	}
	info->nbr = nbr;
	info->nbr_len = ft_nbrlen_base(nbr, info->nbr_base);
	if (info->prec > 0)
		info->prec -= info->nbr_len;
	else
		info->prec = 0;
	info->width -= info->nbr_len + info->prec;
	if (info->nbr_sign == -1 || info->space == 1 || info->showsign == 1)
		info->width -= 1;
	if (info->type == 'p')
		info->width -= 2;
	if (info->left == 0)
		return (set_order_right(info));
	else
		return (set_order_left(info));
}

int	set_order_right(t_info *info)
{
	if (info->width == 0 && info->prec == 0 && info->zero == 0)
		return (run_order(info, put_sign_alt, print_prec_nbr, 0));
	if (info->width == 0 && info->prec == 0 && info->zero == 1)
		return (run_order(info, put_sign_alt, print_prec_nbr, 0));
	if (info->width == 0 && info->prec != 0 && info->zero == 0)
		return (run_order(info, put_sign_alt, print_prec_nbr, 0));
	if (info->width == 0 && info->prec != 0 && info->zero == 1)
		return (run_order(info, put_sign_alt, print_prec_nbr, 0));
	if (info->width != 0 && info->prec == 0 && info->zero == 0)
		return (run_order(info, padding_width, put_sign_alt, print_prec_nbr));
	if (info->width != 0 && info->prec == 0 && info->zero == 1)
		return (run_order(info, put_sign_alt, padding_width, print_prec_nbr));
	if (info->width != 0 && info->prec != 0 && info->zero == 0)
		return (run_order(info, padding_width, put_sign_alt, print_prec_nbr));
	if (info->width != 0 && info->prec != 0 && info->zero == 1)
		return (run_order(info, padding_width, put_sign_alt, print_prec_nbr));
	return (-1);
}

int	set_order_left(t_info *info)
{
	if (info->width == 0 && info->prec == 0)
		return (run_order(info, padding_width, put_sign_alt, print_prec_nbr));
	if (info->width == 0 && info->prec != 0)
		return (run_order(info, padding_width, put_sign_alt, print_prec_nbr));
	if (info->width != 0 && info->prec == 0)
		return (run_order(info, put_sign_alt, print_prec_nbr, padding_width));
	if (info->width != 0 && info->prec != 0)
		return (run_order(info, put_sign_alt, print_prec_nbr, padding_width));
	return (-1);
}

int	ft_putnbr(unsigned long long n, t_info *info)
{
	unsigned long long	ret;
	int					tmp;
	char				*base;

	if (info->type == 'd' || info->type == 'i' || info->type == 'u')
		base = "0123456789";
	else if (info->type == 'x' || info->type == 'p')
		base = "0123456789abcdef";
	else if (info->type == 'X')
		base = "0123456789ABCDEF";
	ret = 0;
	tmp = 0;
	if (n > info->nbr_base - 1)
		tmp = ft_putnbr(n / info->nbr_base, info);
	if (tmp == -1)
		return (-1);
	ret += tmp;
	tmp = write(1, &base[n % info->nbr_base], 1);
	if (tmp == -1)
		return (-1);
	ret += tmp;
	return (ret);
}

int	print_prec_nbr(t_info *info)
{
	int	ret;
	int	tmp;

	ret = 0;
	tmp = 0;
	while (0 < info->prec--)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		ret++;
	}
	tmp = ft_putnbr(info->nbr, info);
	if (tmp == -1)
		return (-1);
	ret += tmp;
	return (ret);
}
