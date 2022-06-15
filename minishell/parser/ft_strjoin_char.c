/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:43:27 by youjeon           #+#    #+#             */
/*   Updated: 2022/06/10 17:45:29 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*ft_strjoin_char(char *s1, char s2)
{
	char	*ret;
	size_t	s1_len;

	if (!s1 && !s2)
	{
		return (0);
	}
	else if (!s1)
	{
		return (ft_strdup(&s2));
	}
	s1_len = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * (s1_len + 2));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, s1_len + 1);
	ft_strlcpy(ret + s1_len, &s2, 2);
	free(s1);
	return (ret);
}
