/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:36:09 by ncheniou          #+#    #+#             */
/*   Updated: 2025/02/04 17:17:37 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	aux;

	aux = 0;
	while (str[aux] != '\0')
	{
		aux ++;
	}
	return (aux);
}

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		(*len) += 1;
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10, len);
	write(1, &"0123456789"[n % 10], 1);
	(*len) += 1;
}

void	*ft_putnbr_base(unsigned long num, char *base, int *len)
{
	unsigned int	i;
	unsigned int	length;

	length = ft_strlen(base);
	i = num;
	if (i >= length)
		ft_putnbr_base(i / length, base, len);
	ft_char(base[i % length]);
	(*len)++;
	return (0);
}

void	ft_putptr(unsigned long n, char *base, int *len)
{
	if (n == 0)
	{
		(*len) += write(1, "(nil)", 5);
		return ;
	}
	(*len) += write(1, "0x", 2);
	ft_putnbr_base(n, base, len);
}
	// if (n >= counter)
	// 	i += ft_putptr(n / counter, base);
	// i += ft_char(base[n % counter]);
	// return (i);