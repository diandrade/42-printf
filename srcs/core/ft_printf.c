#include "../../includes/ft_printf.h"

static int ft_check_and_count(char format, va_list ap)
{
    int len;

    len = 0;
    if (format == 'c' || format == '%')
        len += ft_putchar(va_arg(ap, int));
    if (format == 's')
        len += ft_putstr(va_arg(ap, char *));
    if (format == 'i' || format == 'd')
        len += ft_putnbr(va_arg(ap, long));
    if (format == 'u')
        len += ft_putnbr_unsigned(va_arg(ap, int));
        
    return len;
}

int ft_printf(const char *format, ...)
{
    int counter;
    int totalsum;
    va_list ap;

    if (!format)
        return (-1);
    
    va_start(ap, format);
    counter = 0;
    totalsum = 0;
    while (format[counter])
    {
        if (format[counter] == '%')
        {
            counter++;
            totalsum += ft_check_and_count(format[counter], ap);
        }
        else
            totalsum += ft_putchar(format[counter++]);
        counter++;
    }
    va_end(ap);
    return totalsum;
}
