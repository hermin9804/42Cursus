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

static unsigned int	ft_get_word_cnt(const char *s, char c)
{
	unsigned int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
		}
		++s;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char			**ret;
	char			*from;
	unsigned int	i;

	if (!s)
		return (0);
	ret = (char **)malloc(sizeof(char *) * (ft_get_word_cnt(s, c) + 1));
	if (!ret)
		return (0);
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
			ft_strlcpy(ret[i++], from, s - from + 1);
		}
		++s;
	}
	ret[i] = 0;
	return (ret);
}
