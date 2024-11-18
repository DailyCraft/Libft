/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:23:23 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/17 21:36:23 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*c;

	c = ft_memccpy(dest, src, 0, n);
	if (c)
		ft_bzero(c, n - (c - dest));
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*c;

	if (size != 0)
	{
		c = ft_memccpy(dst, src, 0, size - 1);
		if (!c)
			dst[size - 1] = 0;
	}
	return (ft_strlen(src));
}
