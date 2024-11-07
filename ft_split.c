/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:23:23 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/07 11:10:04 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_split(char const *s, char c)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	add_to_split(char const *s, char c, char **split)
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
			j = 1;
			while (s[i + j] != c && s[i + j])
				j++;
			split[split_part] = malloc((j + 1) * sizeof(char));
			if (!split[split_part])
				return (0);
			ft_memcpy(split[split_part], s + i, j);
			split[split_part++][j] = 0;
			i += j - 1;
		}
		i++;
	}
	return (1);
}

static void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = ft_calloc(count_split(s, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	if (!add_to_split(s, c, split))
	{
		free_split(split);
		return (NULL);
	}
	return (split);
}
