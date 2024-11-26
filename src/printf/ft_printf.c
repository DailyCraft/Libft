/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:49:50 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/26 10:14:07 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	write_printf(int fd, const char *format, va_list *args)
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

static int	get_printf(char **out, const char *format, va_list *args)
{
	int				len;
	t_printf_spec	*next;
	char			*temp;

	len = 0;
	while (1)
	{
		next = get_next_spec(format, args);
		if (next)
		{
			len += printf_post(out, len, (char *) format, next->pos - format);
			len += printf_post(out, len, temp, parse_spec(next, args, &temp));
			format = next->pos + next->unparsed_len;
			free(temp);
			free(next);
		}
		else
		{
			len += printf_post(out, len, (char *) format, ft_strlen(format));
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
	len = write_printf(fd, format, &args);
	va_end(args);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = write_printf(1, format, &args);
	va_end(args);
	return (len);
}

int	ft_asprintf(char **strp, const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	*strp = NULL;
	len = get_printf(strp, format, &args);
	len += printf_post(strp, len, "", 1);
	va_end(args);
	return (len);
}
