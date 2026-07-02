#include "ft_printf.h"

int ft_check_format(char format)
{
    int len;

    if (format == 'c' || format == '%')
        len += ft_print_char(va_arg(args, int));
    if (format == 's')
        len += ft_print_string(va_arg(args, char *));
    if (format == 'p')
        len += ft_print_pointer(va_arg(args, void *));
    if (format == 'd')
        len += ft_print_decimal(va_arg(args, int));
    if (format == 'i')
        len += ft_print_integer(va_arg(args, int));
    if (format == 'u')
        len += ft_print_unsigned_decimal(va_arg(args, unsigned int));
    if (format == 'x')
        len += ft_print_hex_lower(va_arg(args, unsigned int));
    if (format == 'X')
        len += ft_print_hex_upper(va_arg(args, unsigned int));
    return len;
}

int ft_printf(const char *format, ...)
{
    int i;
    int totalsum;
    va_list args;

    va_start(args, format);

    if (!format)
        return (-1);
    
    i = 0;
    totalsum = 0;
    while (format[i])
        if (ft_strlen(format) != 1)
            if (format[i] == '%')
                totalsum += ft_check_and_count(format[++i], args);
        else
            if (format[i] == '%')
                write(1, '%', 1);

    va_end(args);
    return totalsum;
}
