/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:34:07 by yliao             #+#    #+#             */
/*   Updated: 2022/01/21 18:24:33 by yliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	n;
	size_t	i;

	n = ft_strlen(dst);
	if (n >= dstsize)
		return (dstsize + ft_strlen(src));
	i = 0;
	while ((src[i] != '\0' ) && ((n + i) < (dstsize - 1)))
	{
		dst[n + i] = src[i];
		i++;
	}
	dst[n + i] = '\0';
	return (n + ft_strlen(src));
}
