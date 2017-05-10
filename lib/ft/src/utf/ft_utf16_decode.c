/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf16_decode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 12:27:35 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/29 14:54:15 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Decode up to two UTF-16 code units and return a Unicode codepoint.
*/

uint32_t	ft_utf16_decode(const uint16_t *utf16)
{
	uint32_t	utf32;

	if (utf16[0] >= 0xD800 && utf16[0] < 0xDC00
		&& utf16[1] >= 0xDC00 && utf16[1] <= 0xDFFF)
		utf32 = ((utf16[0] & 0x3FF) << 10) | (utf16[1] & 0x3FF);
	else
		utf32 = utf16[0];
	if (utf32 > 0x10FFFF || (utf32 >= 0xD800 && utf32 <= 0xDFFF))
		return (-1);
	return (utf32);
}
