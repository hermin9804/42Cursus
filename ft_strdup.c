/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:13:31 by mher              #+#    #+#             */
/*   Updated: 2021/11/19 17:22:12 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ret;
	char	*tmp;

	len = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	tmp = ret;
	if (!ret)
		return (0);
	while (len--)
	{
		*ret = *s1;
		++ret;
		++s1;
	}
	*ret = 0;
	return (tmp);
}
