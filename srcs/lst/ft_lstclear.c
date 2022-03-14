/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:52:18 by yliao             #+#    #+#             */
/*   Updated: 2022/03/14 19:22:41 by yliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	if (!*lst)
		return ;
	while (*lst)
	{
		ptr = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = ptr;
	}
	*lst = 0;
}
