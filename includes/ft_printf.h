#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* Libraries */
# include <stdarg.h>
# include <unistd.h>

/* Methods */
    /* Core */
        int	ft_printf(const char *format, ...);
    /* Aux */
        static int ft_putchar (char c);
        static int ft_putstr (char *str);
        static int ft_putnbr(long n);
        static int ft_putnbr_unsigned(unsigned int n);
#endif