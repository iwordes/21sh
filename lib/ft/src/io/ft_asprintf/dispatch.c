/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:29:32 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/03 12:57:59 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char		*g_conv_c = "CDOSUXbcdiopsuvx";

static ssize_t	(*g_conv_f[])(char**, va_list, t_printer*) =
{
	ft_asprintf_conv_char_long,
	ft_asprintf_conv_dec_long,
	ft_asprintf_conv_octal_long,
	ft_asprintf_conv_str_long,
	ft_asprintf_conv_unsigned_long,
	ft_asprintf_conv_hex_caps,

	ft_asprintf_conv_binary,
	ft_asprintf_conv_char,
	ft_asprintf_conv_dec,
	ft_asprintf_conv_dec,
	ft_asprintf_conv_octal,
	ft_asprintf_conv_ptr,
	ft_asprintf_conv_str,
	ft_asprintf_conv_unsigned,
	ft_asprintf_conv_invis,
	ft_asprintf_conv_hex,

	ft_asprintf_conv_literal
};

/*
** Launch the proper conversion delegate and enforce minimum field width.
**
** 1. While we do not have the proper conversion function, advance.
**    If we have reached the end of our available valid conversions, stop.
** 2. If we are on a valid conversion function, increment the argument index.
** 3. Execute the proper conversion function and store its output.
**    If its output is less than zero, return it.
** 4. Format the raw string and return the formatter's output.
*/

ssize_t			ft_asprintf_dispatch(char **str, va_list arg, size_t *a,
															t_printer *p)
{
	int		i;
	char	*raw;
	ssize_t	l;

	i = 0;
	while (g_conv_c[i] != p->conv && g_conv_c[i] != 0)
		i += 1;
	if (g_conv_c[i] != 0)
		*a += 1;
	if ((l = g_conv_f[i](&raw, arg, p)) < 0)
		return (l);
	return (ft_asprintf_format(str, raw, l, p));
}
