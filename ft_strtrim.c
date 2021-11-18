#include "libft.h"
#include <stdio.h>//test
#include <stdlib.h>//test

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*ret;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = s1;
	end = s1 + ft_strlen(s1) - 1;
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
	ft_strlcpy(ret, start, end - start);
	return (ret);
}

int	main()
{
	char *s1 = "12hello21";
	char *set = "12";
	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}
