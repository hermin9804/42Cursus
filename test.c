#include <stdio.h>//test
#include <string.h>//test
#include <stdlib.h>//test

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*ret;

	if (!s1)
		return (0);
	if (!set)
		return (strdup(s1));
	start = (char *)s1;
	end = (char *)s1 + strlen(s1) - 1;
	while (*start && strchr(set, *start))
		++start;
	while (end && strchr(set, *end))
	{
		if (end < s1)
			break ;
		--end;
	}
	if (start > end)
		return (strdup(""));
	ret = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!ret)
		return (0);
	strlcpy(ret, start, end - start + 2);
	return (ret);
}

int	main()
{
	char *s1 = "12hello21";
	char *set = "12";
	printf("%s\n", ft_strtrim(s1, set));
	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}
