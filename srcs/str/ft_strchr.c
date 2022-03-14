/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:56:50 by yliao             #+#    #+#             */
/*   Updated: 2022/01/28 10:30:52 by yliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char) c)
		return ((char *)s);
	return (0);
}
