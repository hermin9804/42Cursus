/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:08:36 by youjeon           #+#    #+#             */
/*   Updated: 2022/06/08 17:28:03 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	*ft_getenv(t_env *env_head, char *key)
{
	t_env	*cur;

	cur = compare_env_key(env_head, key);
	return (cur->value);
}
