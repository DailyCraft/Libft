/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:49:50 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/18 11:01:38 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	printf_args(int fd, const char *format, va_list *args)
{
	int				len;
	t_printf_spec	*next;

	len = 0;
	while (1)
	{
		next = get_next_spec(format, args);
		if (next)
		{
			len += write(fd, format, next->pos - format);
			len += write_spec(fd, next, args);
			format = next->pos + next->unparsed_len;
			free(next);
		}
		else
		{
			ft_putstr_fd((char *) format, fd);
			len += ft_strlen(format);
			break ;
		}
	}
	return (len);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = printf_args(fd, format, &args);
	va_end(args);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = printf_args(1, format, &args);
	va_end(args);
	return (len);
}
