/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:23:23 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/18 14:10:00 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (dest);
	i = 0;
	while (i < n)
	{
		((char *) dest)[i] = ((char *) src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *) dest)[i] = ((char *) src)[i];
		if (((char *) dest)[i] == c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			((char *) dest)[i - 1] = ((char *) src)[i - 1];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

void	*ft_memdup(void *src, size_t size)
{
	void	*dest;

	if (size == 0)
		return (NULL);
	dest = malloc(size);
	if (dest)
		ft_memcpy(dest, src, size);
	return (dest);
}

void	*ft_memjoin(void *m1, size_t m1_len, void *m2, size_t m2_len)
{
	void	*join;

	join = malloc(m1_len + m2_len);
	if (!join)
		return (NULL);
	ft_memcpy(join, m1, m1_len);
	ft_memcpy(join + m1_len, m2, m2_len);
	return (join);
}
