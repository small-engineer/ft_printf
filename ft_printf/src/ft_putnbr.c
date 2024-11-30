/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:36:47 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/12/01 04:38:01 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_unsigned(unsigned int n)
{
	char	c;
	int		len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putnbr_unsigned(n / 10);
		c = (n % 10) + '0';
		if (write(1, &c, 1) == -1)
			return (-1);
		len++;
	}
	else
	{
		c = n + '0';
		if (write(1, &c, 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

static int	ft_putnbr_recursive(int n)
{
	char	c;
	int		len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putnbr_recursive(n / 10);
		c = (n % 10) + '0';
		if (write(1, &c, 1) == -1)
			return (-1);
		len++;
	}
	else
	{
		c = n + '0';
		if (write(1, &c, 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		len += ft_putnbr_recursive(-n);
	}
	else
		len += ft_putnbr_recursive(n);
	return (len);
}

int	ft_print_int(va_list *args)
{
	int	n;

	n = va_arg(*args, int);
	return (ft_putnbr(n));
}

int	ft_print_unsigned(va_list *args)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	return (ft_putnbr_unsigned(n));
}
