#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	ret;
	int	cnt;
	int	sign;

	ret = 0;
	cnt = 0;
	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		++str;
		++cnt;
	}
	while ('0' <= *str && *str <= '9')
	{
		ret = ret * 10 + (*str - 48);
		++str;
	}
	if (cnt > 1)
		return (0);
	return (sign * ret);
}

int	main()
{
	printf("%d\n", ft_atoi("2147483647"));
	printf("%d\n", atoi("2147483647"));

	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", atoi("-2147483648"));
	return (0);
}
