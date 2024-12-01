/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:16:34 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/25 16:06:01 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, s1_len + 1);
	ft_strlcat(ret, s2, s1_len + s2_len + 1);
	return (ret);
}
