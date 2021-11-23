/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:42:23 by mher              #+#    #+#             */
/*   Updated: 2021/11/21 17:34:05 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_error(char **ret)
{
	unsigned int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		++i;
	}
	free(ret);
	return (0);
}

static size_t	ft_get_word_cnt(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
			if (!*s)
				break ;
		}
		++s;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*from;
	size_t	i;

	if (!s)
		return (0);
	ret = (char **)ft_calloc(sizeof(char *), (ft_get_word_cnt(s, c) + 1));
	if (!ret)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			from = (char *)s;
			while (*s && *s != c)
				++s;
			ret[i] = (char *)malloc(s - from + 1);
			if (!ret[i])
				return (ft_malloc_error(ret));
			ft_strlcpy(ret[i++], from, s-- - from + 1);
		}
		++s;
	}
	return (ret);
}
