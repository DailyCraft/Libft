/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-hum <dvan-hum@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:48:18 by dvan-hum          #+#    #+#             */
/*   Updated: 2024/11/18 11:00:50 by dvan-hum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <libft.h>

enum e_printf_flags
{
	LEFT_JUSTIFY = 0b1 << 0,
	FORCE_SIGN = 0b1 << 1,
	SPACE_SIGN = 0b1 << 2,
	SPECIFIED_TYPE = 0b1 << 3,
	ZEROES_PADS = 0b1 << 4
};

typedef struct s_printf_spec
{
	const char	*pos;
	int			unparsed_len;
	char		*value;
	char		flags;
	int			width;
	int			precision;
	char		type;
}	t_printf_spec;

void			*ft_or(void *value, void *or_value);
char			*add_pre(char *out, int *len, char *pre);
char			*add_post(char *out, int *len, char *post);

t_printf_spec	*get_next_spec(const char *format, va_list *args);
int				write_spec(int fd, t_printf_spec *spec, va_list *args);

char			*p_type(va_list *args);
void			precisition_idx(t_printf_spec *spec, char **out, int *len);
int				is_reduced(t_printf_spec *spec, char *out, int len);
char			*width_extra(t_printf_spec *spec, int *len,
					char *out, char **neg);

int				out_type(t_printf_spec *spec, va_list *args, char **out);
void			out_precisition(t_printf_spec *spec, char **out, int *len);
void			out_specified_type(t_printf_spec *spec, char **out, int *len);
void			out_force_sign(t_printf_spec *spec, char **out, int *len);
void			out_width(t_printf_spec *spec, char **out, int *len);

#endif