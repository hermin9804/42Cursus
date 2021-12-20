/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:55:12 by mher              #+#    #+#             */
/*   Updated: 2021/12/20 21:03:57 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	print_arg(va_list ap, t_info *info)
{
	int	arg_len;
	char	type;

	arg_len = 0;
	type = info->type;
	if (type == 'c')
		arg_len = print_char(va_arg(ap, int), info);
	else if (type == 's')
		arg_len = print_string(va_arg(ap, char *), info);
	else if (type == 'd' || type == 'i')
		arg_len = print_nbr_int(va_arg(ap, int), info);
	/*else if (type == 'u' || type == 'x' || type == 'X')
		arg_len = print_nbr(va_arg(ap, unsigned int), info);
	else if (type == 'p')
		arg_len = print_nbr(va_arg(ap, unsigned long long), info);*/
	else if (type == '%')
		arg_len = print_char('%', info);
	return (arg_len);
}

/*int	print_nbr_int(int nbr, t_info *info)
{
	int	tmp;
	int	arg_len;
	
	tmp = 0;
	arg_len = 0;
	if (info->minus == 1)
	{
		tmp = ft_putnbr(nbr);
		if (tmp == -1)
			return (ERROR);
		arg_len = tmp;
	}
	tmp += put_width_nbr_flags(nbr, info);
	tmp += put_precision_width(nbr, info);
	if (tmp == -1)
		return (ERROR);
	arg_len += tmp;
	if (info->minus == 0)
	{
		tmp = ft_putnbr(nbr);
		if (tmp == -1)
			return (ERROR);
		arg_len += tmp;
	}
	return (arg_len);
}
*/
