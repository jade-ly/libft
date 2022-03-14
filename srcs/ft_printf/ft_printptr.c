/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:59:26 by yliao             #+#    #+#             */
/*   Updated: 2022/03/01 19:32:56 by yliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(uintptr_t ptr)
{
	int	i;

	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
		{
			i = ptr + '0';
			write(1, &i, 1);
		}
		else
		{
			i = ptr - 10 + 'a';
			write(1, &i, 1);
		}
	}
}

int	ft_lenptr(uintptr_t ptr)
{
	int	n;

	n = 0;
	while (ptr != 0)
	{
		n++;
		ptr = ptr / 16;
	}
	return (n);
}

int	ft_printptr(unsigned long long ptr)
{
	int	n;

	n = write(1, "0x", 2);
	if (ptr == 0)
		n += write(1, "0", 1);
	else
	{
		ft_putptr(ptr);
		n += ft_lenptr(ptr);
	}
	return (n);
}
