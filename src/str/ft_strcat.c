/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:23:23 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/17 21:33:29 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	ft_strcpy(dest + ft_strlen(dest), src);
	return (dest);
}

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	len;
	char	*c;

	len = ft_strlen(dest);
	c = ft_memccpy(dest + len, src, 0, n);
	if (!c)
		dest[len + n] = 0;
	return (dest);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length;

	length = ft_strnlen(dst, size);
	ft_strlcpy(dst + length, src, size - length);
	return (length + ft_strlen(src));
}
