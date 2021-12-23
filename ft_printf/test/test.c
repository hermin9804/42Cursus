#include <stdio.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	print_int(int d)
{
	return (printf("%d", d));
}

int	print_chat_int(int f1(char), int f2(int))
{
	int ret = 0;
	char c = 'c';
	int d = 1;

	ret += f1(c);
	ret += f2(d);
	return (ret);
}

int	main(void)
{
	print_chat_int(ft_putchar, print_int);
	return (0);
}
