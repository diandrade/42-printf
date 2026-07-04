#include "../../includes/ft_printf.h"

int ft_check_and_count(char format, va_list ap)
{
    int len;

    len = 0;
    if (format == 'c' || format == '%')
        len += ft_print_char(va_arg(ap, int));
    if (format == 's')
        len += ft_print_string(va_arg(ap, char *));
    /*if (format == 'p')
        len += ft_print_pointer(va_arg(ap, void *));
    if (format == 'd')
        len += ft_print_decimal(va_arg(ap, int));
    if (format == 'i')
        len += ft_print_integer(va_arg(ap, int));
    if (format == 'u')
        len += ft_print_unsigned_decimal(va_arg(ap, unsigned int));
    if (format == 'x')
        len += ft_print_hex_lower(va_arg(ap, unsigned int));
    if (format == 'X')
        len += ft_print_hex_upper(va_arg(ap, unsigned int));
    */
   return len;
}

int ft_printf(const char *format, ...)
{
    int i;
    int totalsum;
    va_list ap;

    if (!format)
        return (-1);
    
    va_start(ap, format);
    i = 0;
    totalsum = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            totalsum += ft_check_and_count(format[i], ap);
        }
        else
            totalsum += ft_print_char(format[i++]);
        i++;
    }

    va_end(ap);
    return totalsum;
}
