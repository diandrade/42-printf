#include "../../includes/ft_printf.h"

static int ft_putstr(char *str)
{
    int counter;

    if (!str)
    {
        write (1, "(null)", 6);
        return 0;
    }

    counter = 0;
    while(str[counter])
        write (1, &str[counter++], 1);

    return counter;
}