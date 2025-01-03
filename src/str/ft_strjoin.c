/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:23:23 by dvan-hum          #+#    #+#             */
/*   Updated: 2025/01/03 09:56:23 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	return (ft_strsjoin((const char *[]){s1, s2, NULL}));
}

char	*ft_strsjoin(const char **strs)
{
	char	*join;
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (strs[i])
		len += ft_strlen(strs[i++]);
	join = malloc((len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	len = 0;
	while (strs[i])
	{
		ft_strcpy(join + len, strs[i]);
		len += ft_strlen(strs[i]);
		i++;
	}
	return (join);
}
