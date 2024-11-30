/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:36:47 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/12/01 00:36:51 by ywakamiy         ###   ########.fr       */
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
		write(1, &c, 1);
		len++;
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
		len++;
	}
	return (len);
}

static int	ft_putnbr(int n)
{
	char	c;
	int		len;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		write(1, "-", 1);
		len += ft_putnbr(-n) + 1;
	}
	else if (n >= 10)
	{
		len += ft_putnbr(n / 10);
		c = (n % 10) + '0';
		write(1, &c, 1);
		len++;
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
		len++;
	}
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
