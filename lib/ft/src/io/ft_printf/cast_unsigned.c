/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:26:18 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/29 17:27:03 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Casts a va_list to an unsigned integer as specified by printer->length.
*/

uintmax_t	ft_asprintf_cast_unsigned(va_list arg, t_printer *p)
{
	uintmax_t	value;

	value = va_arg(arg, uintmax_t);
	if (p->length & 64)
		return (value);
	else if ((p->length & 32)
		&& ((p->length & 16) == 0 || sizeof(ptrdiff_t) > sizeof(size_t)))
		return ((ptrdiff_t)value);
	else if (p->length & 16)
		return ((size_t)value);
	else if (p->length & 8)
		return ((unsigned long long)value);
	else if (p->length & 4)
		return ((unsigned long)value);
	else if (p->length & 2)
		return ((unsigned short)value);
	else if (p->length & 1)
		return ((unsigned char)value);
	else
		return ((unsigned)value);
}
