/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:43:17 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/27 05:05:16 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*s2;
	const size_t	len = ft_strlen(s1) + 1;

	if (!s1)
		return (NULL);
	s2 = ft_calloc(len, sizeof(char));
	if (s2)
	{
		ft_strlcpy(s2, s1, len);
		return (s2);
	}
	else
		return (NULL);
}
