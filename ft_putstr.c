#include "ft_printf.h"

int	ft_putstr(va_list args)
{
	char	*str;
	int		len;
    int loop_count = 0;

	len = 0;
	str = va_arg(args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		write(1, str++, 1);
        loop_count++;
		len++;
	}
	return (len);
}