#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* Libraries */
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

/* Methods */
    /* Core */
        int	ft_printf(const char *format, ...);
    /* Aux */
        int ft_putchar (char c);
        int ft_putstr (char *str);
        int ft_putnbr(int n);
        int ft_putnbr_unsigned (unsigned int n);
        int ft_puthex (unsigned long n, char letter_case);
        int ft_putptr(unsigned long n);
        
#endif