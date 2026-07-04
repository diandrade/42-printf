#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* Libraries */
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

/* Methods */
int ft_printf(const char *format, ...);
int ft_print_char(char c);
int ft_print_string(char *str);
int ft_strlen(const char *str);
/*
int ft_print_decimal(int nbr);
int ft_print_unsigned(unsigned int nbr);
int ft_print_hex_lower(unsigned int nbr);
int ft_print_hex_upper(unsigned int nbr);
int ft_print_pointer(void *ptr);
int ft_putnbr_base(unsigned long long nbr, char *base);
*/

#endif