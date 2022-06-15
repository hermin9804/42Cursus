/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:41:04 by youjeon           #+#    #+#             */
/*   Updated: 2022/06/08 15:57:12 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	*is_free(char **str, int str_index)
{
	int	i;

	i = 0;
	while (i < str_index)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	get_word_cnt(char const *str, char c)
{
	size_t	count;
	int		chker;

	count = 0;
	chker = 1;
	while (*str != '\0' && *str == c)
		str++;
	while (*str)
	{
		if (chker == 1 && *str != c)
		{
			count++;
			chker = 0;
		}
		if (*str == c)
			chker = 1;
		str++;
	}
	return (count);
}

static char	**set_worddup(char const *s, char c, char **mem)
{
	size_t	word_length;
	int		i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		word_length = 0;
		while (s[word_length] && s[word_length] != c)
			word_length++;
		mem[i] = (char *)malloc(sizeof(char) * (word_length + 1));
		if (!mem[i])
			return (is_free(mem, i));
		ft_strlcpy(mem[i], s, word_length + 1);
		s = s + word_length;
		i++;
	}
	mem[i] = NULL;
	return (mem);
}

char	**ft_split_argc(char const *s, char c, int *argc)
{
	char	**new_mem;

	new_mem = NULL;
	if (!s)
		return (NULL);
	*argc = get_word_cnt(s, c);
	new_mem = (char **)malloc(sizeof(char *) * (*argc + 1));
	if (!new_mem)
		return (NULL);
	new_mem = set_worddup(s, c, new_mem);
	return (new_mem);
}
