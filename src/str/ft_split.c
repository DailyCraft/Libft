/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:23:23 by dvan-hum          #+#    #+#             */
/*   Updated: 2025/02/10 10:46:00 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_split(const char *str, const char *delim)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_strchr(delim, str[i])
			&& (i == 0 || ft_strchr(delim, str[i - 1])))
			count++;
		i++;
	}
	return (count);
}

static int	add_to_split(const char *str, const char *delim, char **split)
{
	int		split_part;
	size_t	i;
	size_t	j;

	split_part = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_strchr(delim, str[i])
			&& (i == 0 || ft_strchr(delim, str[i - 1])))
		{
			j = 1;
			while (!ft_strchr(delim, str[i + j]) && str[i + j])
				j++;
			split[split_part] = malloc((j + 1) * sizeof(char));
			if (!split[split_part])
				return (0);
			ft_memcpy(split[split_part], str + i, j);
			split[split_part++][j] = 0;
			i += j - 1;
		}
		i++;
	}
	return (1);
}

char	**ft_split(const char *str, const char *delim)
{
	char	**split;

	split = ft_calloc(count_split(str, delim) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	if (!add_to_split(str, delim, split))
	{
		ft_free_split(split);
		return (NULL);
	}
	return (split);
}

void	ft_free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
