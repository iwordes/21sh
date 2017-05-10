/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strluntil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:40:23 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:16:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** A version of struntil with a search limit.
*/

size_t		ft_strluntil(const char *string, char c, size_t limit)
{
	size_t	i;

	i = 0;
	if (string != NULL)
	{
		while (string[i] != 0 && i < limit)
		{
			if (string[i] == c)
				return (i);
			i++;
		}
	}
	return (i);
}
