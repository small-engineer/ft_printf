/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:07:12 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/27 03:57:41 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*head = s1;
	const char	*tail;
	size_t		len;
	char		*ret;

	if (!s1 || !set)
		return (NULL);
	tail = s1 + ft_strlen(s1) - 1;
	while (*head && ft_strchr(set, *head))
		head++;
	while (tail >= head && ft_strchr(set, *tail))
		tail--;
	len = (tail - head) + 2;
	ret = (char *)ft_calloc(len, sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, head, len);
	ret[len - 1] = '\0';
	return (ret);
}
