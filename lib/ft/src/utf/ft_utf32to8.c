/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf32to8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 10:08:27 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/16 10:45:51 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Convert a zero-terminated array of Unicode codepoints into a UTF-8 string.
*/
/*
** Things to watch out for:
** - Without over-allocating the string, using ft_utf8_encode would cause a
** segfault towards the end of the string. (ft_utf8_encode returns a uint32)
*/

uint8_t		*ft_utf32to8(const uint32_t *utf32)
{
	uint8_t		*utf8;
	size_t		i;

	i = 0;
	utf8 = (uint8_t*)ft_memalloc(ft_utf32to8_len(utf32) + 5);
	while (*utf32 != 0)
	{
		if ((*(uint32_t*)(utf8 + i) = ft_utf8_encode(*utf32)) == (uint32_t)-1)
		{
			free(utf8);
			return (NULL);
		}
		if (*utf32 < 0x800)
			i += (*utf32 < 0x80) ? 1 : 2;
		else
			i += (*utf32 < 0x10000) ? 3 : 4;
		utf32 += 1;
	}
	return (utf8);
}
