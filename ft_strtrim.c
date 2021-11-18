#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*ret;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = (char *)s1;
	end = (char *)*s1 + ft_strlen(s1) - 1;
	while (*start && ft_strchr(set, *start))
		++start;
	while (end && ft_strchr(set, *end))
	{
		if (end < s1)
			break ;
		--end;
	}
	if (start > end)
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, start, end - start + 2);
	return (ret);
}
