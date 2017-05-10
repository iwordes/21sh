/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rjust.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 20:18:50 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/31 20:22:56 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Internal function for accurately right-justifying a raw conversion segment.
*/

char	*ft_asprintf_rjust(char *string, char pad, size_t target, size_t length)
{
	char	*padded;
	size_t	i;

	NULL_GUARD(string);
	i = 0;
	NULL_GUARD(padded = ft_strnew(MAX(target, i)));
	if (length < target)
		while (i + length < target)
			padded[i++] = pad;
	ft_memcpy(padded + i, string, length);
	return (padded);
}
