/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf32to8_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:48:03 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/29 15:20:21 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Determine the length of a zero-terminated array of Unicode codepoints if
** encoded as a UTF-8 string.
*/

size_t	ft_utf32to8_len(const uint32_t *utf32)
{
	size_t	l;

	l = 0;
	while (*utf32 != 0)
	{
		if (*utf32 < 0x800)
			l += (*utf32 < 0x80) ? 1 : 2;
		else
			l += (*utf32 < 0x100000) ? 3 : 4;
		utf32 += 1;
	}
	return (l);
}
