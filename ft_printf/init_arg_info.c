/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:16:34 by mher              #+#    #+#             */
/*   Updated: 2021/12/18 14:58:25 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_arg_info(t_arg_info *arg_info)
{
	arg_info->alternate = 0;
	arg_info->zero = 0;
	arg_info->minus = 0;
	arg_info->plus = 0;
	arg_info->space = 0;
	arg_info->width = 0;
	arg_info->precision = -1;
	arg_info->type = 0;
	arg_info->nbr_sign = 0;
	arg_info->nbr_base = 10;
}
