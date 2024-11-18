/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:13:23 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/13 09:05:27 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_spec(const char *s)
{
	size_t	i;

	if (s[0] != '%')
		return (0);
	i = 1;
	while (ft_strchr("-+ #0", s[i]))
		i++;
	if (s[i] == '*')
		i++;
	else
		while (ft_isdigit(s[i]))
			i++;
	if (s[i] == '.')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] && ft_strchr("cspdiuxX%", s[i]))
		return (++i);
	return (0);
}

static size_t	define_flags(t_printf_spec *spec, const char *fmt, size_t len)
{
	size_t	i;

	spec->flags = 0;
	i = 1;
	while (i < len)
	{
		if (fmt[i] == '-')
			spec->flags |= LEFT_JUSTIFY;
		else if (fmt[i] == '+')
			spec->flags |= FORCE_SIGN;
		else if (fmt[i] == ' ')
			spec->flags |= SPACE_SIGN;
		else if (fmt[i] == '#')
			spec->flags |= SPECIFIED_TYPE;
		else if (fmt[i] == '0')
			spec->flags |= ZEROES_PADS;
		else
			break ;
		i++;
	}
	return (i);
}

static t_printf_spec	*parse_spec(char *format, size_t len, va_list *args)
{
	t_printf_spec	*spec;
	size_t			i;
	char			*precision;

	spec = calloc(1, sizeof(t_printf_spec));
	if (!spec)
		return (NULL);
	spec->pos = format;
	spec->unparsed_len = len;
	i = define_flags(spec, format, len);
	if (format[i] == '*')
		spec->width = va_arg(*args, int);
	else
		spec->width = ft_atoi(format + i);
	precision = ft_memchr(format, '.', len);
	if (precision && precision[1] == '*')
		spec->precision = va_arg(*args, int);
	else if (precision)
		spec->precision = ft_atoi(precision + 1);
	else
		spec->precision = -1;
	spec->type = format[len - 1];
	return (spec);
}

t_printf_spec	*get_next_spec(const char *format, va_list *args)
{
	size_t	i;
	int		spec_len;

	i = 0;
	while (format[i])
	{
		spec_len = is_spec(format + i);
		if (spec_len != 0)
			return (parse_spec((char *) format + i, spec_len, args));
		i++;
	}
	return (NULL);
}

int	write_spec(int fd, t_printf_spec *spec, va_list *args)
{
	char	*out;
	int		len;
	int		width_first;

	if (spec->type == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	out = NULL;
	len = out_type(spec, args, &out);
	if (spec->precision != -1)
		out_precisition(spec, &out, &len);
	width_first = spec->flags & ZEROES_PADS && spec->precision == -1;
	if (spec->width > len && width_first)
		out_width(spec, &out, &len);
	out_force_sign(spec, &out, &len);
	out_specified_type(spec, &out, &len);
	if (spec->width > len && !width_first)
		out_width(spec, &out, &len);
	write(fd, out, len);
	free(out);
	return (len);
}
