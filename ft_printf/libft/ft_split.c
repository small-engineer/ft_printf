/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:17:46 by ywakamiy          #+#    #+#             */
/*   Updated: 2024/10/30 20:23:58 by ywakamiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_words(const char *s, char c)
{
	size_t	count;
	bool	in_word;

	count = 0;
	in_word = false;
	while (*s)
	{
		if (!in_word && *s != c)
		{
			in_word = true;
			count++;
		}
		else if (*s == c)
			in_word = false;
		s++;
	}
	return (count);
}

static char	*word_dup(const char *s, int start, int end)
{
	char	*word;
	size_t	w_len;

	w_len = end - start;
	word = (char *)ft_calloc(w_len + 1, sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + start, w_len + 1);
	return (word);
}

static void	handle_word(char const *s, char c, char **ret, size_t *index)
{
	size_t	i;
	int		start;

	i = 0;
	start = -1;
	while (s[i])
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || s[i + 1] == '\0') && start >= 0)
		{
			if (s[i] == c)
				ret[(*index)++] = word_dup(s, start, i);
			else
				ret[(*index)++] = word_dup(s, start, i + 1);
			start = -1;
		}
		i++;
	}
}

static void	free_split(char **split)
{
	if (!split)
		return ;
	while (*split)
		free(*split++);
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char		**ret;
	size_t		i;
	size_t		ii;

	if (!s)
		return (NULL);
	ret = (char **)ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	ii = 0;
	handle_word(s, c, ret, &i);
	while (ii < i)
	{
		if (!ret[ii++])
		{
			free_split(ret);
			return (NULL);
		}
	}
	ret[i] = NULL;
	return (ret);
}
