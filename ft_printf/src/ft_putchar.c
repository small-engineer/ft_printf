/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:36:38 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/12/01 09:23:50 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}
