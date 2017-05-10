/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struntils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:54:20 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:16:57 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** ft_struntils(const char *string, const char *find)
** ============
** Returns either the index of the first valid occurrence of find in string, or
** the index of the string's terminating NUL.
*/

size_t		ft_struntils(const char *string, const char *substring)
{
	size_t	i;
	size_t	sl;

	i = 0;
	if (string != NULL && substring != NULL)
	{
		sl = ft_strlen(substring);
		while (string[i] != 0 && !ft_strnequ(string, substring, sl))
			i++;
	}
	return (i);
}
