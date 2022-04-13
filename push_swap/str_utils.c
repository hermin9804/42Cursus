/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:55:04 by mher              #+#    #+#             */
/*   Updated: 2022/04/13 12:16:18 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	long	ret;
	int		sign;

	ret = 0;
	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		++str;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	if (*str < '0' || '9' < *str)
		error_exit();
	while ('0' <= *str && *str <= '9')
	{
		ret = (ret * 10) + ((*str - '0') * sign);
		if (ret < INT_MIN || INT_MAX < ret)
			error_exit();
		if (*str < '0' || '9' < *str)
			error_exit();
		++str;
	}
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, s1_len + 1);
	ft_strlcpy(ret + s1_len, s2, s2_len + 1);
	return (ret);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ret;
	char	*tmp;

	len = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	tmp = ret;
	while (len--)
	{
		*tmp = *s1;
		++tmp;
		++s1;
	}
	*tmp = 0;
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		++i;
		++s;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (destsize == 0)
		return (src_len);
	while (src[i] && i < (destsize - 1))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = 0;
	return (src_len);
}
