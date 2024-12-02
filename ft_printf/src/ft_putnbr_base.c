/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:36:55 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/12/03 03:00:34 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid_base(const char *base)
{
	const char	*p_1;
	const char	*p_2;

	if (!base || ft_strlen(base) < 2)
		return (0);
	p_1 = base;
	while (*p_1)
	{
		if (*p_1 == '+' || *p_1 == '-')
			return (0);
		p_2 = p_1 + 1;
		while (*p_2)
		{
			if (*p_1 == *p_2)
				return (0);
			p_2++;
		}
		p_1++;
	}
	return (1);
}

static int	ft_putnbr_base(unsigned long n, const char *base)
{
	unsigned int	base_len;
	char			buf[17];
	char			*p_buf;
	int				written;

	if (!is_valid_base(base))
		return (-1);
	base_len = ft_strlen(base);
	written = 0;
	p_buf = buf;
	while (n >= base_len)
	{
		*p_buf++ = base[n % base_len];
		n /= base_len;
	}
	*p_buf++ = base[n];
	while (p_buf != buf)
	{
		if (write(1, --p_buf, 1) == -1)
			return (-1);
		written++;
	}
	return (written);
}

int	ft_print_pointer(va_list *args)
{
	unsigned long	p;
	int				len;

	len = 0;
	p = (unsigned long)va_arg(*args, void *);
	if (p == 0)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	len += 2 + ft_putnbr_base(p, "0123456789abcdef");
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
