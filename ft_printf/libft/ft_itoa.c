/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:19:53 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/30 10:55:14 by ywakamiy         ###   ########.fr       */
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

char	*ft_itoa(int n)
{
	int				len;
	char			*ret;
	unsigned int	num;

	len = get_digit_i(n);
	ret = (char *)ft_calloc((len + 1), sizeof(char));
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	num = handle_sign(n, ret);
	fill_digits(ret, num, len - 1);
	return (ret);
}
