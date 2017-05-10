/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8to16_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:49:54 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/29 15:22:37 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Return the byte length of a VALID UTF-8 string if re-encoded in UTF-16.
*/

size_t	ft_utf8to16_len(const uint8_t *utf8)
{
	size_t	i;
	size_t	l;
	size_t	t;

	i = 0;
	l = 0;
	while (utf8[i] != 0)
	{
		if ((utf8[i] & 0xE0) == 0xE0)
			t = ((utf8[i] & 0xF0) == 0xF0) ? 4 : 3;
		else
			t = ((utf8[i] & 0x80) == 0x80) ? 2 : 1;
		l += (t < 4) ? 1 : 2;
		i += t;
	}
	return (l);
}
