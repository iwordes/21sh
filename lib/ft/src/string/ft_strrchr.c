/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:44:54 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:16:34 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Given a string and a character, locates the last occurance of that character
** and returns a pointer to it.
*/

char	*ft_strrchr(const char *string, char find)
{
	char	*current;

	current = (char*)string + ft_strlen(string);
	while (current >= string)
	{
		if (*current == find)
			return (current);
		current--;
	}
	return (NULL);
}
