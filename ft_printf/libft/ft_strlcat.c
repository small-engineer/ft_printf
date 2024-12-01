/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:19:07 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/27 04:00:58 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*p_dst;
	const char	*p_src = src;
	size_t		i;
	size_t		d_len;

	p_dst = dst;
	i = dstsize;
	while (i-- != 0 && *p_dst)
		p_dst++;
	d_len = p_dst - dst;
	i = dstsize - d_len;
	if (i == 0)
		return (d_len + ft_strlen(p_src));
	while (*p_src)
	{
		if (i != 1)
		{
			*p_dst++ = *p_src;
			i--;
		}
		p_src++;
	}
	*p_dst = '\0';
	return (d_len + (p_src - src));
}
