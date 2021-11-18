#include "libft.h"

static void	ft_print_nbr(int n, int fd)
{
	char *num = "0123456789";

	if (n > 9)
		ft_print_nbr(n / 10, fd);
	write(fd, &num[n % 10], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	ft_print_nbr(n, fd);
}
