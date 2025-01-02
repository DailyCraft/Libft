/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:41:25 by dvan-hum          #+#    #+#             */
/*   Updated: 2025/01/02 13:45:28 by dvan-hum         ###   ########.fr       */
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
		lst = &(*lst)->next;
	}
	return (0);
}
