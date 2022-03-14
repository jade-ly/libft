/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:25:57 by yliao             #+#    #+#             */
/*   Updated: 2022/03/01 19:16:27 by yliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_printspecial(va_list args, const char format)
{
	int	n;

	n = 0;
	if (format == 'c')
		n += ft_printchar(va_arg(args, int));
	else if (format == 's')
		n += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		n += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		n += ft_printint(va_arg(args, int));
	else if (format == 'u')
		n += ft_printunsigned(va_arg(args, unsigned int), 10, 0);
	else if (format == 'x')
		n += ft_printunsigned(va_arg(args, unsigned int), 16, 0);
	else if (format == 'X')
		n += ft_printunsigned(va_arg(args, unsigned int), 16, 1);
	else if (format == '%')
		n += ft_printchar('%');
	return (n);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		n;
	va_list	args;

	i = 0;
	n = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			n += ft_printchar(str[i]);
		else
		{
			i++;
			n += ft_printspecial(args, str[i]);
		}
		i++;
	}
	return (n);
}
