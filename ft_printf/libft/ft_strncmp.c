/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:58:59 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/27 03:30:57 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	while (n--)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 != c2)
			return (c1 - c2);
		if (!c1)
			break ;
	}
	return (0);
}
