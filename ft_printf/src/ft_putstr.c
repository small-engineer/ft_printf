/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:37:09 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/12/01 04:42:17 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(va_list *args)
{
	char	*str;
	int		len;

	len = 0;
	str = va_arg(*args, char *);
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (*str != '\0')
	{
		if (write(1, str++, 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}
