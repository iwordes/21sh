/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ws_segs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:47:05 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/19 12:48:35 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Number of whitespace segments
*/

size_t	ws_segs(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str != 0)
	{
		while (*str != 0 && !ft_isspace(*str))
			str += 1;
		if (*str != 0)
			cnt += 1;
		while (ft_isspace(*str))
			str += 1;
	}
	return (cnt);
}
