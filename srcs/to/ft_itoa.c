/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:10:10 by yliao             #+#    #+#             */
/*   Updated: 2022/03/14 19:28:26 by yliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_digits(int n)
{
	size_t			digit;
	int				sign;
	unsigned int	n2;

	sign = 1;
	if (n < 0)
		sign = -1;
	n2 = n * sign;
	digit = 1;
	while (n2 / 10 > 0)
	{
		n2 = n2 / 10;
		digit++;
	}
	if (sign < 0)
		return (digit + 1);
	return (digit);
}

char	*ft_itoa(int n)
{
	char			*dst;
	size_t			digit;
	int				sign;
	unsigned int	n2;

	digit = ft_count_digits(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	n2 = n * sign;
	dst = malloc(sizeof(char) * (digit + 1));
	if (!dst)
		return (0);
	dst[digit] = '\0';
	while (n2 / 10 > 0)
	{
		dst[--digit] = (n2 % 10) + '0';
		n2 = n2 / 10;
	}
	dst[--digit] = (n2 % 10) + '0';
	if (sign < 0)
		dst[digit - 1] = '-';
	return (dst);
}
