/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 06:45:01 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/29 02:53:04 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*next_node;

	next_node = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!next_node)
		return (NULL);
	next_node->content = content;
	next_node->next = NULL;
	return (next_node);
}
