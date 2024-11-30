/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:35:28 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/12/01 05:12:09 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(const char *fmt, va_list *args)
{
	static int	(*fmt_func[])(va_list *) = {
		&ft_putchar, &ft_putstr,
		ft_print_pointer, &ft_print_int, &ft_print_int, &ft_print_unsigned,
		&ft_print_hex_lowercase, &ft_print_hex_uppercase, &ft_print_percent
	};
	const char	p_fmt_chars[] = "cspdiuxX%";
	int			p_fmt_len;

	p_fmt_len = 0;
	while (p_fmt_chars[p_fmt_len])
	{
		if (*fmt == p_fmt_chars[p_fmt_len])
			return ((*fmt_func[p_fmt_len])(args));
		p_fmt_len++;
	}
	return (write(1, fmt, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		ret;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			ret = ft_format(++format, &args);
			if (ret == -1)
				return (va_end(args), -1);
			count += ret;
		}
		else
		{
			ret = write(1, format, 1);
			if (ret == -1)
				return (va_end(args), -1);
			count += ret;
		}
		format++;
	}
	return (va_end(args), count);
}
