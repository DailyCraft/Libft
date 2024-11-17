/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:38:38 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/17 20:39:24 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (((char *) s1)[i] == ((char *) s2)[i] && i < n - 1)
		i++;
	return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *) s)[i] == (char) c)
			return ((void *) s + i);
		i++;
	}
	return (NULL);
}
