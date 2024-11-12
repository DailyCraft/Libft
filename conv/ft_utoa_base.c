/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:23:23 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/12 14:05:47 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	digit_count(unsigned int n, size_t base_len)
{
	if (n < base_len)
		return (1);
	return (1 + digit_count(n / base_len, base_len));
}

char	*ft_utoa_base(unsigned int n, char *base)
{
	char	*str;
	int		str_len;
	size_t	base_len;
	int		i;

	base_len = ft_strlen(base);
	str_len = digit_count(n, base_len);
	str = malloc((str_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = str_len - 1;
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i--] = base[n % base_len];
		n /= base_len;
	}
	str[str_len] = 0;
	return (str);
}
