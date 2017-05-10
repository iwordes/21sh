/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:40:26 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/31 10:35:44 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Parses length modifiers, e.g. "ll", "hh", "j", "z", etc.
**
** length is a single-byte value specified by the following bitset:
** { 0 }{ 000 } { 00 } { 00 }
**  alt  misc.   long  short
** alt: Unused (sign) bit. For future length modifiers.
** misc: 3-bit number detailing an "odd" type (e.g. size_t, ptrdiff_t)
**     01xx: "j" (intmax_t)
**     0x1x: "t" (ptrdiff_t)
**     0xx1: "z" (size_t)
** long: 01 is "l", 10 is "ll"
** short: 01 is "h", 10 is "hh"
**
** length      mask        new length
** 0000 0001 ^ 0000 0011 = 0000 0010
** 0000 0010 ^ 0000 0011 = 0000 0001
**
** 0000 0100 ^ 0000 1100 = 0000 1000
** 0000 1000 ^ 0000 1100 = 0000 0100
*/

char	ft_asprintf_parse_length(const char **fmt, t_printer *p)
{
	if (**fmt == 'h' && (p->length & 3) == 0)
		p->length |= 2;
	else if (**fmt == 'h')
		p->length = (p->length & 0xFC) + ((p->length & 3) ^ 3);
	else if (**fmt == 'l' && (p->length & 12) == 0)
		p->length |= 4;
	else if (**fmt == 'l')
		p->length = (p->length & 0xF3) + ((p->length & 12) ^ 12);
	else if (**fmt == 'z')
		p->length |= 16;
	else if (**fmt == 't')
		p->length |= 32;
	else if (**fmt == 'j')
		p->length |= 64;
	if (**fmt == 'h' || **fmt == 'l' || **fmt == 'z' || **fmt == 't'
		|| **fmt == 'j')
		return ((char)(*fmt += 1) | 1);
	else
		return (FALSE);
}
