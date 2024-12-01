/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 02:46:11 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/29 02:52:44 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		ret;
	t_list	*curr;

	ret = 0;
	curr = lst;
	while (curr)
	{
		ret++;
		curr = curr->next;
	}
	return (ret);
}
