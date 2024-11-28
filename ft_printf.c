/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:33:08 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/11/28 20:44:25 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static int	ft_format(const char *fmt, va_list args)
{
	static const char	*fmt_chars = "cspdiuxX%";
	const char			*p_fmt_chars = fmt_chars;

	static int (*fmt_func[])(va_list) = {&ft_putchar, &ft_putstr,
		&ft_print_pointer, &ft_print_int, &ft_print_int, &ft_print_unsigned,
		&ft_print_hex_lowercase, &ft_print_hex_uppercase, &ft_print_percent};
	while (*p_fmt_chars)
	{
		if (*fmt == *p_fmt_chars)
			return ((*fmt_func[p_fmt_chars - fmt_chars])(args));
		p_fmt_chars++;
	}
	return (write(1, fmt, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_format(&format[++i], args);
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
