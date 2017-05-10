/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:38:09 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/01 16:39:09 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

ssize_t	ft_asprintf_conv_hex(char **string, va_list arg, t_printer *p)
{
	uintmax_t	integer;

	integer = ft_asprintf_cast_unsigned(arg, p);
	if (integer == 0 && p->prec == 0)
		*string = ft_strdup("");
	else
		*string = ft_asprintf_uitoa_base(integer, 16, p);
	if (*string == NULL)
		return (-1);
	if (p->alt && integer > 0 && !(p->zero_pad && p->width > 0))
		(*string)[1] = p->conv;
	return (ft_strlen(*string));
}
