/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:41:09 by yliao             #+#    #+#             */
/*   Updated: 2022/03/14 19:25:44 by yliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char	*s, char c)
{
	size_t	i;
	size_t	n;
	int		sign;

	i = 0;
	n = 0;
	sign = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && sign == 0)
		{
			sign = -1;
			n++;
		}
		else if (s[i] == c)
			sign = 0;
		i++;
	}
	return (n);
}

size_t	ft_word_len(const char	*s, char c)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0' && s[n] != c)
		n++;
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	i;
	size_t	j;

	dst = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!s || !dst)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			dst[j++] = ft_substr(s, i, ft_word_len(s + i, c));
			i += ft_word_len(s + i, c);
		}
		else
			i++;
	}
	dst[j] = 0;
	return (dst);
}
