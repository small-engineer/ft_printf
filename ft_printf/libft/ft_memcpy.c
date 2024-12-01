/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:36:18 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/27 04:46:37 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	char	*p_src;
	char	*p_dest;

	p_src = (char *)src;
	p_dest = (char *)dest;
	if (!dest && !src)
		return (NULL);
	while (count--)
		*p_dest++ = *p_src++;
	return (dest);
}
