/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:23:23 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/05 12:21:28 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	digit_count(int n)
{
	if (n >= -9 && n <= 9)
		return (1 + (n < 0));
	return (1 + digit_count(n / 10));
}

static void	place_digits(int n, char *str, int length)
{
	int	i;

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
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i--] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;

	length = digit_count(n);
	str = malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	place_digits(n, str, length);
	str[length] = 0;
	return (str);
}
