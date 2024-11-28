#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

// ft_printf.c
int	ft_printf(const char *format, ...);

// ft_putchar.c
int	ft_putchar(va_list args);

// ft_putstr.c
int	ft_putstr(va_list args);

// ft_putnbr.c
int	ft_print_int(va_list args);
int	ft_print_unsigned(va_list args);

// ft_putnbr_base.c
int	ft_print_pointer(va_list args);
int	ft_print_hex_lowercase(va_list args);
int	ft_print_hex_uppercase(va_list args);
int	ft_print_percent(va_list args);

//strlen
size_t	ft_strlen(const char *s);

#endif
