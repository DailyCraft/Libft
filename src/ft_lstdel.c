/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:41:25 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/15 16:35:41 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del)
		del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}

int	ft_lstdeli(t_list **lst, int index, void (*del)(void *))
{
	int		i;
	t_list	*next;

	i = 0;
	while (*lst)
	{
		if (index == i)
		{
			next = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = next;
			return (1);
		}
		i++;
	}
	return (0);
}
