/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 08:57:07 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/25 10:59:36 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	decimal(const char *str)
{
	double	result;
	int		count;
	size_t	i;

	result = 0;
	count = 10;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		result += (double)(str[i] - '0') / count;
		count *= 10;
		i++;
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	result;
	char	neg;
	size_t	i;

	result = 0;
	neg = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
		result += decimal(str + i + 1);
	return (result * neg);
}
