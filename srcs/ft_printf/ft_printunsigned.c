/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:15:30 by yliao             #+#    #+#             */
/*   Updated: 2022/03/01 19:40:54 by yliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_count_digits2(unsigned int nbr, int base)
{
	size_t	digit;

	digit = 1;
	while (nbr / base > 0)
	{
		nbr = nbr / base;
		digit++;
	}
	return (digit);
}

void	ft_stock_digit(char *dst, unsigned int nbr, int base, int lettercase)
{
	if (nbr % base <= 9)
		*dst = (nbr % base) + '0';
	else if (lettercase == 0)
		*dst = (nbr % base) - 10 + 'a';
	else
		*dst = (nbr % base) - 10 + 'A';
}

char	*ft_uitoa(unsigned int nbr, int base, int lettercase)
{
	char	*dst;
	size_t	digit;

	digit = ft_count_digits2(nbr, base);
	dst = malloc(sizeof(char) * (digit + 1));
	if (!dst)
		return (0);
	dst[digit] = '\0';
	while (nbr / base > 0)
	{
		digit--;
		ft_stock_digit(dst + digit, nbr, base, lettercase);
		nbr = nbr / base;
	}
	digit--;
	ft_stock_digit(dst + digit, nbr, base, lettercase);
	return (dst);
}

int	ft_printunsigned(unsigned int nbr, int base, int lettercase)
{
	int		n;
	char	*str;

	str = ft_uitoa(nbr, base, lettercase);
	n = ft_printstr(str);
	free(str);
	return (n);
}
