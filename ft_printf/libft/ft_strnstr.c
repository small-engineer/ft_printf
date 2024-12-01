/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:40:45 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/25 12:15:43 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;

	if (!*needle)
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	while (len > 0 && *haystack)
	{
		if (*haystack == *needle)
			if (n_len <= len && ft_strncmp(haystack, needle, n_len) == 0)
				return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
