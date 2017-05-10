/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:45:00 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:16:42 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Counts the similar characters between two given strings, in order.
** Semantically, the return value is both the number of characters similar, and
** the index of the first difference.
*/

size_t		ft_strsim(const char *string1, const char *string2)
{
	size_t	similar;

	similar = 0;
	if (string1 != NULL && string2 != NULL)
		while (string1[similar] == string2[similar])
			similar++;
	return (similar);
}
