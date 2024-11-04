/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:23:23 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/04 16:27:00 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	digit_count(int n)
{
	char	count;

	if (n >= -9 && n <= 9)
		return (1 + (n < 0));
	return (1 + digit_count(n / 10));
}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;
	int		i;

	length = digit_count(n);
	str = malloc(length + 1);
	i = length - 1;
	if (n == MIN_INT)
	{
		str[i--] = '8';
		n /= 10;
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		str[i] = n % 10 + '0';
		i--;
		n /= 10;
	}
}
