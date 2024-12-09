/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:23:23 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/09 08:19:55 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	if (!lst)
		return (0);
	return (1 + ft_lstsize(lst->next));
}

t_list	*ft_lstgeti(t_list *lst, int index)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (index == i)
			return (lst);
		i++;
		lst = lst->next;
	}
	return (NULL);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

int	ft_lstindex(t_list *lst, void *content, int (*cmp)(void *, void *))
{
	int	i;

	i = 0;
	while (lst)
	{
		if (cmp)
		{
			if (cmp(lst->content, content) == 0)
				return (i);
		}
		else if (lst->content == content)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}
