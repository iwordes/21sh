/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8_decode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 10:27:36 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/29 15:14:09 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Decode a left-justified UTF-8 sequence into a Unicode codepoint.
** Returns (wint_t)-1 on error.
*/
/*
** Things that need to be validated:
** - Are there enough continuations to meet the header's sequence length?
** -
*/

static uint32_t	ft_utf8_decode_4b(const uint8_t utf8[4])
{
	if (!IS_UTF8_CONT(utf8[1]) || !IS_UTF8_CONT(utf8[2])
		|| !IS_UTF8_CONT(utf8[3]))
		return (-1);
	return ((utf8[0] & 0x07 << 18) | (utf8[1] & 0x3F << 12)
			| (utf8[2] & 0x3F << 6) | (utf8[3] & 0x3F));
}

static uint32_t	ft_utf8_decode_3b(const uint8_t utf8[3])
{
	if (!IS_UTF8_CONT(utf8[1]) || !IS_UTF8_CONT(utf8[2]))
		return (-1);
	return ((utf8[0] & 0x0F << 12) | (utf8[1] & 0x3F << 6) | (utf8[2] & 0x3F));
}

static uint32_t	ft_utf8_decode_2b(const uint8_t utf8[2])
{
	if (!IS_UTF8_CONT(utf8[1]))
		return (-1);
	return ((utf8[0] & 0x1F << 6) | (utf8[1] & 0x3F));
}

uint32_t		ft_utf8_decode(const uint8_t *utf8)
{
	uint32_t	utf32;

	if (IS_UTF8_ASCII(utf8[0]))
		return (utf8[0]);
	else if (IS_UTF8_H2(utf8[0]))
		utf32 = ft_utf8_decode_2b(utf8);
	else if (IS_UTF8_H3(utf8[0]))
		utf32 = ft_utf8_decode_3b(utf8);
	else if (IS_UTF8_H4(utf8[0]))
		utf32 = ft_utf8_decode_4b(utf8);
	else
		return (-1);
	if (utf32 > 0x10FFFF || (utf32 >= 0xD800 && utf32 <= 0xDFFF))
		return (-1);
	return (utf32);
}
