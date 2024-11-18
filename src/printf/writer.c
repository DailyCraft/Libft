/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:04:55 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/13 09:04:41 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_type(t_printf_spec *spec, va_list *args, char **out)
{
	if (spec->type == 'c')
		*out = ft_strdup((char [2]){va_arg(*args, int), 0});
	else if (spec->type == 's')
	{
		spec->value = va_arg(*args, char *);
		*out = ft_strdup(ft_or(spec->value, "(null)"));
	}
	else if (spec->type == 'd' || spec->type == 'i')
		*out = ft_itoa(va_arg(*args, int));
	else if (spec->type == 'u')
		*out = ft_utoa_base(va_arg(*args, unsigned int), "0123456789");
	else if (spec->type == 'x')
		*out = ft_utoa_base(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (spec->type == 'X')
		*out = ft_utoa_base(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (spec->type == 'p')
		*out = p_type(args);
	if (spec->type == 'c')
		return (1);
	return (ft_strlen(*out));
}

void	out_precisition(t_printf_spec *spec, char **out, int *len)
{
	char	*temp;

	if (spec->type == 's')
	{
		if (spec->precision < *len)
		{
			if (spec->value != 0)
			{
				temp = ft_substr(*out, 0, spec->precision);
				*len = spec->precision;
			}
			else
			{
				temp = ft_strdup("");
				*len = 0;
			}
			free(*out);
			*out = temp;
		}
	}
	else if (spec->type != 'c' && spec->type != 'p')
		precisition_idx(spec, out, len);
}

void	out_specified_type(t_printf_spec *spec, char **out, int *len)
{
	int	i;

	if (spec->type == 'x' || spec->type == 'X')
	{
		i = 0;
		while (i < *len && ((*out)[i] == '0' || (*out)[i] == ' '))
			i++;
		if (!(spec->flags & SPECIFIED_TYPE) || i == *len)
			return ;
	}
	else if (spec->type != 'p' || (*out)[0] == '(')
		return ;
	if (spec->type == 'X')
		*out = add_pre(*out, len, "0X");
	else
		*out = add_pre(*out, len, "0x");
}

void	out_force_sign(t_printf_spec *spec, char **out, int *len)
{
	if ((spec->type == 'd' || spec->type == 'i') && ft_antoi(*out, *len) >= 0)
	{
		if (spec->flags & FORCE_SIGN)
			*out = add_pre(*out, len, "+");
		else if (spec->flags & SPACE_SIGN)
			*out = add_pre(*out, len, " ");
	}
}

void	out_width(t_printf_spec *spec, char **out, int *len)
{
	char	*extra;
	char	*neg;

	neg = NULL;
	extra = width_extra(spec, len, *out, &neg);
	if (spec->flags & LEFT_JUSTIFY)
		*out = add_post(*out, len, extra);
	else
		*out = add_pre(*out, len, extra);
	if (neg)
		*ft_strchr(*out, '0') = '-';
	free(extra);
}
