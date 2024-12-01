/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 03:06:02 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/27 03:25:12 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	char			*p_s;

	if (!s || !f)
		return ;
	i = 0;
	p_s = s;
	while (*p_s)
		f(i++, p_s++);
}
