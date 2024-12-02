/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:41:25 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/02 13:10:54 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*next;

	if (del)
		del(lst->content);
	next = lst->next;
	free(lst);
	return (next);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	while (*lst)
		*lst = ft_lstdelone(*lst, del);
}

int	ft_lstdeli(t_list **lst, int index, void (*del)(void *))
{
	int	i;

	i = 0;
	while (*lst)
	{
		if (i == index)
		{
			*lst = ft_lstdelone(*lst, del);
			return (1);
		}
		i++;
	}
	return (0);
}
