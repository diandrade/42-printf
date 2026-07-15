/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieandra <dieandra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 09:21:28 by dieandra          #+#    #+#             */
/*   Updated: 2026/07/15 09:24:39 by dieandra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_puthex(unsigned long n, char letter_case)
{
	int		count;
	char	*base;

	if (letter_case == 'X')
	{
		base = "0123456789ABCDEF";
	}
	else
	{
		base = "0123456789abcdef";
	}
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, letter_case);
	return (ft_putchar(base[n % 16]) + count);
}
