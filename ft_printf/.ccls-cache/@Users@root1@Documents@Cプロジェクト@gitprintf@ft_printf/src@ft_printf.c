/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussato <yussato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:33:08 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/12/01 00:31:35 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>

#include "ft_printf.h"

static int ft_format(const char *fmt, va_list *args) {
  static int (*fmt_func[])(va_list *) = {&ft_putchar,
                                         &ft_putstr,
                                         &ft_print_pointer,
                                         &ft_print_int,
                                         &ft_print_int,
                                         &ft_print_unsigned,
                                         &ft_print_hex_lowercase,
                                         &ft_print_hex_uppercase,
                                         &ft_print_percent};
  const char p_fmt_chars[] = "cspdiuxX%";
  int p_fmt_len;

  p_fmt_len = 0;
  while (p_fmt_chars[p_fmt_len]) {
    if (*fmt == p_fmt_chars[p_fmt_len])
      return ((*fmt_func[p_fmt_len])(args));
    p_fmt_len++;
  }
  return (write(1, fmt, 1));
}

int ft_printf(const char *format, ...) {
  va_list args;
  size_t count;
  size_t i;

  count = 0;
  i = 0;
  va_start(args, format);
  while (format[i]) {
    if (format[i] == '%')
      count += ft_format(&format[++i], &args);
    else
      count += write(1, &format[i], 1);
    i++;
  }
  va_end(args);
  return (count);
}
