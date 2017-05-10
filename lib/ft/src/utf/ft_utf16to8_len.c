/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf16to8_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:48:06 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/29 15:05:35 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Return the byte length of a VALID UTF-16 string if re-encoded in UTF-8.
*/

size_t	ft_utf16to8_len(const uint16_t *utf16)
{
	uint32_t	codept;
	size_t		i;
	size_t		l;

	i = 0;
	l = 0;
	while (utf16[i] != 0)
	{
		if (utf16[i] >= 0xD800 && utf16[i] < 0xDFFF)
		{
			codept = (utf16[i] & 0x3FF << 10) | (utf16[i + 1] & 0x3FF);
			if (codept >= 0x800)
				l += (codept < 0x100000) ? 3 : 4;
			else
				l += 2;
			i += 1;
		}
		else
			l += (utf16[i] < 0x80) ? 1 : 2;
		i += 1;
	}
	return (l);
}
