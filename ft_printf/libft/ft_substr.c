/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:09:36 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/25 14:15:52 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	ret_len;
	char	*ret;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	if (s_len - start < len)
		ret_len = s_len - start;
	else
		ret_len = len;
	ret = (char *)ft_calloc(ret_len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s + start, ret_len + 1);
	return (ret);
}
