/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_signed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:24:39 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/29 17:23:12 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Casts a va_list to a signed integer as specified by printer->length.
*/

intmax_t	ft_asprintf_cast_signed(va_list arg, t_printer *p)
{
	intmax_t	value;

	value = va_arg(arg, intmax_t);
	if (p->length & 64)
		return (value);
	else if (p->length & 32
		&& ((p->length & 16) == 0 || sizeof(ptrdiff_t) > sizeof(size_t)))
		return ((ptrdiff_t)value);
	else if (p->length & 16)
		return ((ssize_t)value);
	else if (p->length & 8)
		return ((long long)value);
	else if (p->length & 4)
		return ((long)value);
	else if (p->length & 2)
		return ((short)value);
	else if (p->length & 1)
		return ((char)value);
	else
		return ((int)value);
}
