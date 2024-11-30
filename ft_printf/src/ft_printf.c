/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:35:28 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/12/01 08:44:25 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(const char *fmt, va_list *args)
{
	int					i;
	static t_fmt_map	fmt_map[] = {
	{'c', &ft_putchar}, {'s', &ft_putstr},
	{'p', &ft_print_pointer}, {'d', &ft_print_int},
	{'i', &ft_print_int}, {'u', &ft_print_unsigned},
	{'x', &ft_print_hex_lowercase},	{'X', &ft_print_hex_uppercase},
	{'%', &ft_print_percent}, {'\0', NULL}
	};

	i = 0;
	if (!fmt)
		return (-1);
	while (fmt_map[i].fmt_char != '\0')
	{
		if (*fmt == fmt_map[i].fmt_char)
			return (fmt_map[i].fmt_func(args));
		i++;
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
