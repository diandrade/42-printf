#include "../../includes/ft_printf.h"

static int ft_putnbr(int n)
{
	int	totalsum;

	totalsum = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		totalsum += 1;
		n = -n;
	}
	
	if (n >= 10)
	{
		totalsum += ft_putnbr(n / 10);
	}
	
	n = (n % 10) + '0';
	write(1, &n, 1);
	totalsum += 1;
	return (totalsum);
}