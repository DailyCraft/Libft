/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:11:50 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/12/02 21:40:56 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_pre(char *out, int *len, char *pre)
{
	char	*join;
	size_t	pre_len;

	pre_len = ft_strlen(pre);
	join = ft_memjoin(pre, pre_len, out, *len);
	if (!join)
		return (NULL);
	free(out);
	*len += pre_len;
	return (join);
}

char	*add_post(char *out, int *len, char *post)
{
	char	*join;
	size_t	post_len;

	post_len = ft_strlen(post);
	join = ft_memjoin(out, *len, post, post_len);
	if (!join)
		return (NULL);
	free(out);
	*len += post_len;
	return (join);
}

int	printf_post(char **out, int len, char *post, int post_len)
{
	ft_free_set((void **) out,
		ft_memjoin(*out, len, post, post_len));
	return (post_len);
}

int	write_spec(int fd, t_printf_spec *next, va_list *args)
{
	int		len;
	char	*spec;

	len = write(fd, spec, parse_spec(next, args, &spec));
	free(spec);
	return (len);
}
