#include "../../includes/ft_printf.h"

int ft_putptr(unsigned long n)
{
    int count;

    count = 0;
    if (!n)
    {
        count += ft_putstr("(nil)");
        return count;
    }

    count += ft_putstr("0x");
    count += ft_puthex(n, 'x');

    return count;
}