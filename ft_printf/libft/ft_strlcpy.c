/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:13:49 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/25 12:16:00 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*p_dst;
	const char	*p_src;
	size_t		i;

	p_dst = dst;
	p_src = src;
	i = dstsize;
	if (i == 0)
		return (ft_strlen(src));
	while (i-- > 1 && *p_src)
		*p_dst++ = *p_src++;
	*p_dst = '\0';
	while (*p_src++)
		;
	return (p_src - src - 1);
}
