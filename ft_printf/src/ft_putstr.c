/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:37:09 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/12/01 00:37:18 by ywakamiy         ###   ########.fr       */
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
