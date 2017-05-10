/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ljust.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 20:13:50 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/31 20:34:02 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Internal function for accurately left-justifying a raw conversion segment.
*/

char	*ft_asprintf_ljust(char *string, char pad, size_t target, size_t i)
{
	char	*padded;

	NULL_GUARD(string);
	NULL_GUARD(padded = ft_strnew(MAX(target, i)));
	ft_memcpy(padded, string, i);
	while (i < target)
		padded[i++] = pad;
	return (padded);
}
