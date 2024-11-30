#include "ft_printf.h"
#include <stdio.h>

int	ft_putstr(va_list *args)
{
	char	*str;
	int		len;

	len = 0;
	str = va_arg(*args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str != '\0')
	{
		write(1, str++, 1);
		len++;
	}
	return (len);
}