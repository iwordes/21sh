/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struntil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:45:10 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:16:56 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Get the forward distance from the starting pointer *string* until the first
** instance of the character to match. If no match is found, it returns the
** index of the string's terminator.
** - If the string is NULL, returns 0.
*/

size_t		ft_struntil(const char *string, char match)
{
	size_t	i;

	i = 0;
	if (string != NULL)
		while (string[i] != 0 && string[i] != match)
			i++;
	return (i);
}
