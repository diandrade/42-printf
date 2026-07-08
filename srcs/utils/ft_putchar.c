#include "../../includes/ft_printf.h"

static int ft_putchar(char c)
{
    if (!c)
    {
        write (1, "(null)", 6);
        return 0;
    }

    write (1, &c, 1);
    return 1;
}