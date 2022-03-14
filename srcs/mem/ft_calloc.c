/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:31:39 by yliao             #+#    #+#             */
/*   Updated: 2022/03/14 19:24:11 by yliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;
	size_t	total;

	total = size * count;
	dst = malloc(sizeof(char) * total);
	if (!dst)
		return (0);
	ft_memset(dst, 0, count * size);
	return (dst);
}
