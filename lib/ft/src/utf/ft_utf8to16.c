/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8to16.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:44:43 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/29 15:23:52 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Convert a UTF-8 encoded string to a UTF-16 encoded string.
*/

uint16_t	*ft_utf8to16(const uint8_t *utf8)
{
	uint32_t	codept;
	uint16_t	*utf16;
	size_t		i;

	i = 0;
	NULL_GUARD(utf8);
	NULL_GUARD(utf16 = (uint16_t*)ft_memalloc(ft_utf8to16_len(utf8) + 4));
	while (*utf8 != 0)
	{
		if ((codept = ft_utf8_decode(utf8)) == (uint32_t)-1)
		{
			free(utf16);
			return (NULL);
		}
		*(uint32_t*)(utf16 + i) = codept;
		if (codept < 0x800)
			utf8 += ((codept < 0x80) ? 1 : 2);
		else
			utf8 += ((codept < 0x100000) ? 3 : 4);
		i += (codept <= 0xFFFF) ? 1 : 2;
	}
	return (utf16);
}
