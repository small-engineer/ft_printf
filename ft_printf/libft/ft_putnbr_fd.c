/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 06:07:55 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/27 06:13:14 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit_i(int n)
{
	int	i;

	if (n <= 0)
		i = 1;
	else
		i = 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static unsigned int	handle_sign(int n, char *ret)
{
	if (n < 0)
	{
		ret[0] = '-';
		return (-n);
	}
	return (n);
}

static void	fill_digits(char *ret, unsigned int num, int index)
{
	while (index >= 0)
	{
		ret[index--] = '0' + (num % 10);
		num /= 10;
		if (num == 0)
			break ;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	const int			len = get_digit_i(n);
	char				buf_n[12];
	const unsigned int	num = handle_sign(n, buf_n);

	fill_digits(buf_n, num, len - 1);
	buf_n[len] = '\0';
	ft_putstr_fd(buf_n, fd);
}
