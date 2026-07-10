#include "../../includes/ft_printf.h"

int ft_putnbr_unsigned(unsigned int n)
{
	int	totalsum;

	totalsum = 0;
	
	if (n >= 10)
	{
		totalsum += ft_putnbr_unsigned(n / 10);
	}
	
	n = (n % 10) + '0';
	write(1, &n, 1);
	totalsum += 1;
	return (totalsum);
}