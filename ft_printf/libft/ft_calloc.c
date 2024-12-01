/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:05:14 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/27 04:51:26 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	size_total;
	void	*p;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	size_total = count * size;
	if (size_total)
		p = malloc(size_total);
	else
		p = malloc(1);
	if (p)
		ft_memset(p, 0, size_total);
	return (p);
}
