/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:22:07 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/13 08:27:39 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*p_type(va_list *args)
{
	unsigned long	temp_ul;

	temp_ul = va_arg(*args, unsigned long);
	if (temp_ul)
		return (ft_ultoa_base(temp_ul, "0123456789abcdef"));
	return (ft_strdup("(nil)"));
}

void	precisition_idx(t_printf_spec *spec, char **out, int *len)
{
	char	*temp;
	char	*neg;

	neg = ft_strchr(*out, '-');
	if (spec->precision == 0 && ft_strncmp(*out, "0", 2) == 0)
	{
		free(*out);
		*out = ft_strdup("");
		*len = 0;
	}
	else if (*len < spec->precision + (neg != NULL))
	{
		if (neg)
			*neg = '0';
		temp = malloc(spec->precision - *len + (neg != NULL) + 1);
		ft_memset(temp, '0', spec->precision - *len + (neg != NULL));
		temp[spec->precision - *len + (neg != NULL)] = 0;
		if (neg)
			*neg = '0';
		*out = add_pre(*out, len, temp);
		if (neg)
			*ft_strchr(*out, '0') = '-';
		free(temp);
	}
}

int	is_reduced(t_printf_spec *spec, char *out, int len)
{
	int	reduced;

	reduced = 0;
	if (spec->flags & FORCE_SIGN || spec->flags & SPACE_SIGN)
	{
		if (spec->flags & ZEROES_PADS && spec->precision == -1)
		{
			if (ft_antoi(out, len) >= 0)
				reduced = spec->width > len;
			else
				reduced = spec->width < len;
		}
	}
	if (spec->flags & SPECIFIED_TYPE)
	{
		if (spec->type == 'x'
			&& ft_antoi_base(out, len, "0123456789abcdef") != 0)
			reduced = ft_min(2, spec->width - len) + reduced;
		else if (spec->type == 'X'
			&& ft_antoi_base(out, len, "0123456789ABCDEF") != 0)
			reduced = ft_min(2, spec->width - len) + reduced;
	}
	return (reduced);
}

char	*width_extra(t_printf_spec *spec, int *len, char *out, char **neg)
{
	char	*extra;
	int		reduced;

	reduced = is_reduced(spec, out, *len);
	extra = malloc((spec->width - *len + 1 - reduced) * sizeof(char));
	if (spec->flags & ZEROES_PADS && !(spec->flags & LEFT_JUSTIFY)
		&& spec->precision == -1)
	{
		ft_memset(extra, '0', spec->width - *len - reduced);
		if (spec->type == 'd' || spec->type == 'i')
		{
			*neg = ft_strchr(out, '-');
			if (*neg)
				**neg = '0';
		}
	}
	else
		ft_memset(extra, ' ', spec->width - *len - reduced);
	extra[spec->width - *len - reduced] = 0;
	return (extra);
}
