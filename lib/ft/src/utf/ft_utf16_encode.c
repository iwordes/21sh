/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf16_encode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 12:49:56 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/29 15:04:46 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Encode a Unicode codepoint as up to two UTF-16 code units in a wint_t.
*/

uint32_t	ft_utf16_encode(uint32_t utf32)
{
	uint32_t	utf16;
	uint16_t	*cu;

	if (utf32 >= 0xD800 && utf32 <= 0xDFFF)
		return (-1);
	if (utf32 <= 0xFFFF)
		return (utf32);
	else
	{
		cu = (uint16_t*)&utf16;
		cu[0] = 0xD800 | ((utf32 >> 10) & 0x3FF);
		cu[1] = 0xDC00 | (utf32 & 0x3FF);
		return (utf16);
	}
}
