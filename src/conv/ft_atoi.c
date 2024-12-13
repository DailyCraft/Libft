/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:23:23 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/13 19:42:50 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	unclear;

	return (ft_clear_atoi(str, &unclear));
}

int	ft_clear_atoi(const char *str, int *unclear)
{
	unsigned int	result;
	int				neg;

	result = 0;
	neg = 1;
	*unclear = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str - '0';
		if (result > (unsigned) MAX_INT + (neg == -1) && *unclear == 0)
			*unclear = 2;
		str++;
	}
	if (*str)
		*unclear += 1;
	return (result * neg);
}
