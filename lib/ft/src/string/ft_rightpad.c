/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rightpad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:59 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/30 14:17:31 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Given a char* string, a char pad, and a size_t target, returns a new string
** that meets the given target, filling any characters necessary with the given
** fill character.
*/

char	*ft_rightpad(const char *string, char pad, size_t target)
{
	char	*padded_string;
	size_t	i;

	if (string != NULL)
	{
		i = ft_strlen(string);
		NULL_GUARD(padded_string = ft_strnew(ft_greater(target, i)));
		ft_strcat(padded_string, string);
		while (i < target)
			padded_string[i++] = pad;
		return (padded_string);
	}
	return (NULL);
}
