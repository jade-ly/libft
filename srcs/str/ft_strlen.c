/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:20:50 by yliao             #+#    #+#             */
/*   Updated: 2022/01/21 16:50:35 by yliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_strlen(char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i] != '\0')
	{
		i += 1;
	}
	return (i);
}
