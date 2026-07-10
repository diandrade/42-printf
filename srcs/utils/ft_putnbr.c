#include "../../includes/ft_printf.h"

int ft_putnbr(int n)
{
    int       totalsum;
    long long n_long;

    totalsum = 0;
    n_long = n;
    if (n_long < 0)
    {
        write(1, "-", 1);
        totalsum += 1;
        n_long = -n_long;
    }
    if (n_long >= 10)
    {
        totalsum += ft_putnbr(n_long / 10);
    }
    totalsum += ft_putchar((n_long % 10) + '0');
    return (totalsum);
}