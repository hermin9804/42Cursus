#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ret;

	len = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	while (*s1)
	{
		*ret = *s1;
		++ret;
		++s1;
	}
	*ret = 0;
	return (ret);
}
