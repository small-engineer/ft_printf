/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:36:55 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/12/01 00:38:38 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, const char *base)
{
	int				len;
	unsigned int	base_len;
	char			c;

	len = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		len += ft_putnbr_base(n / base_len, base);
		c = base[n % base_len];
		write(1, &c, 1);
		len++;
	}
	else
	{
		c = base[n];
		write(1, &c, 1);
		len++;
	}
	return (len);
}

int	ft_print_pointer(va_list *args)
{
	unsigned long	ptr;
	int				len;

	len = 0;
	ptr = (unsigned long)va_arg(*args, void *);
	write(1, "0x", 2);
	len += 2 + ft_putnbr_base(ptr, "0123456789abcdef");
	return (len);
}

int	ft_print_hex_lowercase(va_list *args)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	return (ft_putnbr_base(n, "0123456789abcdef"));
}

int	ft_print_hex_uppercase(va_list *args)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	return (ft_putnbr_base(n, "0123456789ABCDEF"));
}

int	ft_print_percent(va_list *args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}
