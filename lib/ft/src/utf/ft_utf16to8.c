/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf16to8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:43:48 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/29 15:23:35 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Convert a UTF-16 (wchar_t) string to a UTF-8 (char) string.
** Both strings must/will be NUL-terminated.
*/

uint8_t		*ft_utf16to8(const uint16_t *utf16)
{
	uint32_t	codept;
	uint8_t		*utf8;
	size_t		i;

	i = 0;
	NULL_GUARD(utf16);
	NULL_GUARD(utf8 = ft_memalloc(ft_utf16to8_len(utf16) + 5));
	while (*utf16 != 0)
	{
		codept = ft_utf16_decode(utf16);
		if ((*(uint32_t*)utf8 = ft_utf8_encode(codept)) == (uint32_t)-1)
		{
			free(utf8);
			return (NULL);
		}
		if (codept < 0x800)
			i += (codept < 0x80) ? 1 : 2;
		else
			i += (codept < 0x100000) ? 3 : 4;
		utf16 += (codept <= 0xFFFF) ? 1 : 2;
	}
	return (utf8);
}
