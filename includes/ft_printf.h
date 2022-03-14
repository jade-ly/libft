/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:11:15 by yliao             #+#    #+#             */
/*   Updated: 2022/03/14 19:30:47 by yliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		ft_printspecial(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
void	ft_putptr(uintptr_t ptr);
int		ft_lenptr(uintptr_t ptr);
int		ft_printptr(unsigned long long ptr);
int		ft_printint(int nbr);
size_t	ft_count_digits2(unsigned int nbr, int base);
char	*ft_uitoa(unsigned int nbr, int base, int lettercase);
int		ft_printunsigned(unsigned int nbr, int base, int lettercase);
void	ft_stock_digit(char *dst, unsigned int nbr, int base, int lettercase);

#endif
