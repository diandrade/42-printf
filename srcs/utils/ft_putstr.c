#include "../../includes/ft_printf.h"

int ft_putstr(char *str)
{
    int counter;

    if (!str)
    {
        write(1, "(null)", 6);
        return (6);
    }
    counter = 0;
    while (str[counter])
    {
        write(1, &str[counter], 1);
        counter++;
    }
    return (counter);
}