/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:23:23 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/18 11:08:51 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trim;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]) != NULL)
		start++;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end - 1]) != NULL)
		end--;
	if (s1[start] == 0)
		return (ft_strdup(""));
	trim = malloc((end - start + 1) * sizeof(char));
	if (trim)
		ft_strlcpy(trim, s1 + start, end - start + 1);
	return (trim);
}
