/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:55:12 by mher              #+#    #+#             */
/*   Updated: 2021/12/19 18:58:37 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	print_arg(va_list ap, t_arg_info arg_info)
{
	int	arg_len;
	char	type;

	arg_len = 0;
	type = arg_info.type;
	if (type == 'c')
		arg_len = print_char(va_arg(ap, int), arg_info);
/*	else if (type == 's')
		arg_len = print_string(va_arg(ap, char *), arg_info);
	else if (type == 'd' || type == 'i')
		arg_len = print_nbr(va_arg(ap, int), arg_info);
	else if (type == 'u' || type == 'x' || type == 'X')
		arg_len = print_nbr(va_arg(ap, unsigned int), arg_info);
	else if (type == 'p')
		arg_len = print_nbr(va_arg(ap, unsigned long long), arg_info);*/
	else if (type == '%')
		arg_len = print_char('%', arg_info);
	return (arg_len);
}
