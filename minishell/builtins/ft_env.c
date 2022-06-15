/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:37:24 by mher              #+#    #+#             */
/*   Updated: 2022/06/06 14:34:35 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"

int	ft_env(t_env *cur)
{
	while (cur->key != 0)
	{
		ft_write(STDOUT_FILENO, cur->key, ft_strlen(cur->key));
		ft_write(STDOUT_FILENO, "=", 1);
		ft_write(STDOUT_FILENO, cur->value, ft_strlen(cur->value));
		ft_write(STDOUT_FILENO, "\n", 1);
		cur = cur->next;
	}
	return (EXIT_SUCCESS);
}
