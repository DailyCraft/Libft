/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:11:50 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/13 08:23:58 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_or(void *value, void *or_value)
{
	if (value)
		return (value);
	return (or_value);
}

char	*add_pre(char *out, int *len, char *pre)
{
	char	*join;
	size_t	pre_len;

	pre_len = ft_strlen(pre);
	join = malloc((*len + pre_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_memcpy(join, pre, pre_len);
	ft_memcpy(join + pre_len, out, *len);
	free(out);
	*len += pre_len;
	return (join);
}

char	*add_post(char *out, int *len, char *post)
{
	char	*join;
	size_t	post_len;

	post_len = ft_strlen(post);
	join = malloc((*len + post_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_memcpy(join, out, *len);
	ft_memcpy(join + *len, post, post_len);
	free(out);
	*len += post_len;
	return (join);
}
