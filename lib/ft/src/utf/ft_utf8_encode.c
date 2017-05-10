/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8_encode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 10:33:03 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/29 15:03:21 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Encode a given Unicode codepoint into up to four UTF-8 bytes in a wint_t.
*/

#define H4(V) (0xF0 | ((V) & 0x07))
#define H3(V) (0xE0 | ((V) & 0x0F))
#define H2(V) (0xC0 | ((V) & 0x1F))
#define CONT(V) (0x80 | ((V) & 0x3F))

uint32_t	ft_utf8_encode(uint32_t utf32)
{
	uint8_t		*bytes;
	uint32_t	utf8;
	int			b;

	if (utf32 > 0x10FFFF || (utf32 >= 0xD800 && utf32 <= 0xDFFF))
		return (-1);
	b = 0;
	utf8 = 0;
	bytes = (uint8_t*)&utf8;
	if (utf32 >= 0x10000)
		bytes[b++] = H4(utf32 >> 18);
	if (utf32 >= 0x800)
		bytes[b++] = (utf32 >= 0x10000) ? CONT(utf32 >> 12) : H3(utf32 >> 12);
	if (utf32 >= 0x80)
		bytes[b++] = (utf32 >= 0x800) ? CONT(utf32 >> 6) : H2(utf32 >> 6);
	bytes[b] = (utf32 >= 0x80) ? CONT(utf32) : utf32;
	return (utf8);
}
