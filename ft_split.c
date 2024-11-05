/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:23:23 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/05 15:37:02 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_split(char const *s, char c)
{
	int		count;
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	add_to_split(char const *s, char c, char **split)
{
	int		split_part;
	size_t	i;
	size_t	j;

	split_part = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			j = 0;
			while (s[i + j] != c)
				j++;
			split[split_part] = malloc((j + 1) * sizeof(char));
			ft_memcpy(split[split_part], s + i, j);
			split[split_part++][j] = 0;
			i += j - 1;
		}
		i++;
	}
	split[split_part] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = malloc((count_split(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	add_to_split(s, c, split);
	return (split);
}
