/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:41:37 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/12 14:05:34 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_antoi(const char *nptr, size_t len)
{
	return (ft_antoi_base(nptr, len, "0123456789"));
}

int	ft_antoi_base(const char *str, size_t len, const char *base)
{
	size_t	base_len;
	int		result;
	int		is_neg;
	size_t	i;

	base_len = ft_strlen(base);
	result = 0;
	is_neg = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_neg = -1;
		i++;
	}
	while (i < len && ft_strchr(base, str[i]))
	{
		result = result * base_len + (ft_strchr(base, str[i]) - base);
		i++;
	}
	return (result * is_neg);
}
