/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:34:53 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/12/01 10:30:10 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_fmt_map
{
	char	fmt_char;
	int		(*fmt_func)(va_list *);
}			t_fmt_map;

int			ft_printf(const char *format, ...);

int			ft_putchar(va_list *args);

int			ft_putstr(va_list *args);

int			ft_print_int(va_list *args);
int			ft_print_unsigned(va_list *args);

int			ft_print_pointer(va_list *args);
int			ft_print_hex_lowercase(va_list *args);
int			ft_print_hex_uppercase(va_list *args);

int			ft_print_percent(va_list *args);

#endif
