/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:23:23 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/15 16:34:46 by dvan-hum         ###   ########.fr       */
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

int	ft_lstcontains(t_list *lst, void *content, int (*cmp)(void *, void *))
{
	while (lst)
	{
		if (cmp)
		{
			if (cmp(lst->content, content) == 0)
				return (1);
		}
		else
		{
			if (lst->content == content)
				return (1);
		}
		lst = lst->next;
	}
	return (0);
}
