/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:02:33 by cgrasser          #+#    #+#             */
/*   Updated: 2025/01/07 14:20:59 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_new(void *content)
{
	t_btree	*btree;

	btree = malloc(sizeof(t_btree));
	if (!btree)
		return (NULL);
	btree->content = content;
	btree->left = NULL;
	btree->right = NULL;
	return (btree);
}

void	ft_btree_clear(t_btree **btree, void (*del)(void *))
{
	if (!*btree)
		return ;
	ft_btree_clear(&(*btree)->left, del);
	ft_btree_clear(&(*btree)->right, del);
	if (del)
		del((*btree)->content);
	ft_free_set((void **) btree, NULL);
}
