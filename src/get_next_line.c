/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:43:56 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/13 10:43:56 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_expand_result(char *temp, char **result, size_t *len, int *err)
{
	if (!temp)
	{
		*err = 1;
		return (0);
	}
	if (*len > 0)
		free(*result);
	*result = temp;
	return (1);
}

static char	*fdchr(int fd, char **result, size_t *len, int *err)
{
	char	*temp;
	char	*buf;
	ssize_t	count;
	char	*chr;

	chr = ft_memchr(*result, '\n', *len);
	if (chr)
		return (chr);
	buf = malloc(BUFFER_SIZE);
	count = read(fd, buf, BUFFER_SIZE);
	while (count > 0)
	{
		temp = ft_memjoin(*result, *len, buf, count);
		if (!ft_expand_result(temp, result, len, err))
			break ;
		*len += count;
		chr = ft_memchr(*result, '\n', *len);
		if (chr)
			break ;
		count = read(fd, buf, BUFFER_SIZE);
	}
	if (count == -1)
		*err = 1;
	free(buf);
	return (chr);
}

static char	*next_line(int fd, char **buf, size_t *buf_len, int *end)
{
	char	*result;
	size_t	len;
	char	*chr;
	int		err;

	chr = fdchr(fd, buf, buf_len, (err = 0, &err));
	if (chr && !err)
		len = chr + 1 - *buf;
	else if (*buf_len > 0 && !err)
		len = *buf_len;
	else
		return (NULL);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	(ft_memcpy(result, *buf, len), result[len] = 0);
	if (chr && !ft_free_set((void **) buf, ft_memdup(chr + 1, *buf_len - len)))
	{
		*buf_len = len;
		*end = 1;
	}
	else if (!chr)
		*end = 1;
	*buf_len -= len;
	return (result);
}

static t_file_line	**get_file(t_file_line **files, int fd)
{
	while (*files && (*files)->fd != fd)
		files = &(*files)->next;
	if (!*files)
	{
		*files = malloc(sizeof(t_file_line));
		if (!*files)
			return (NULL);
		(*files)->fd = fd;
		(*files)->buf = NULL;
		(*files)->buf_len = 0;
		(*files)->next = NULL;
	}
	return (files);
}

char	*get_next_line(int fd)
{
	static t_file_line	*files;
	t_file_line			**current;
	char				*line;
	int					end;

	current = get_file(&files, fd);
	if (!current)
		return (NULL);
	end = 0;
	line = next_line(fd, &(*current)->buf, &(*current)->buf_len, &end);
	if (end || !line)
	{
		free((*current)->buf);
		ft_free_set((void **) current, (*current)->next);
	}
	return (line);
}
