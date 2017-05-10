/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leftpad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:42:49 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/30 14:01:24 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Given a char* string, a char pad, and a size_t target, creates a new string
** padded with the given character on the left.
** - If the given string is NULL, does nothing.
** - If the given string is too long to pad, a copy of it is returned.
** - If
*/

char		*ft_leftpad(const char *string, char pad, size_t target)
{
	char	*padded_string;
	size_t	length;
	size_t	i;

	if (string != NULL)
	{
		i = 0;
		length = ft_strlen(string);
		padded_string = ft_strnew(ft_greater(target, length));
		NULL_GUARD(padded_string);
		if (length < target)
			while (i < target - length)
				padded_string[i++] = pad;
		ft_strcat(padded_string, string);
		return (padded_string);
	}
	return (NULL);
}
