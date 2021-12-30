/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:55:12 by mher              #+#    #+#             */
/*   Updated: 2021/12/29 22:54:29 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	print_arg(va_list ap, t_info *info)
{
	char	type;

	type = info->type;
	if (type == 'c')
		return (print_char(va_arg(ap, char), info));
	else if (type == 's')
		return (print_string(va_arg(ap, char *), info));
	else if (type == 'd' || type == 'i')
		return (print_nbr(va_arg(ap, int), info));
	else if (type == 'u' || type == 'x' || type == 'X')
		return (print_nbr(va_arg(ap, unsigned int), info));
	else if (type == 'p')
		return (print_nbr(va_arg(ap, unsigned long long), info));
	else
		return (print_char('%', info));
}
