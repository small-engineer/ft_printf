/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@studelent.42tokyo.jp>     +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 23:45:56 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/23 23:48:37 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*org_dst;
	char	*p_dst;
	char	*p_src;

	org_dst = dst;
	p_dst = (char *)dst;
	p_src = (char *)src;
	if (p_src < p_dst)
	{
		p_src += len;
		p_dst += len;
		while (len-- != 0)
			*(--p_dst) = *(--p_src);
	}
	else if (p_src != p_dst)
		while (len-- != 0)
			*p_dst++ = *p_src++;
	return (org_dst);
}
