/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:13:10 by yliao             #+#    #+#             */
/*   Updated: 2022/01/21 12:22:14 by yliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	size;
	int	i;

	size = ft_lstsize(lst);
	i = 0;
	while (i < size - 1)
	{
		lst = lst -> next;
		i++;
	}
	return (lst);
}
