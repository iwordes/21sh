/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:42:10 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:14:32 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Returns the number of characters in the given string that match the given
** character.
** - If passed NULL, returns 0.
*/

size_t		ft_charcnt(const char *string, char find)
{
	size_t	c;

	c = 0;
	if (string != NULL)
		while (*string != 0)
		{
			if (*string == find)
				c++;
			string++;
		}
	return (c);
}
