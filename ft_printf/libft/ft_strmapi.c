/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 00:22:00 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/27 00:37:38 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*str;
	const char		*p_s = s;
	char			*p_str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	p_str = str;
	i = 0;
	while (*p_s)
		*p_str++ = (*f)(i++, *p_s++);
	return (str);
}
