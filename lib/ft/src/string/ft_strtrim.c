/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:45:08 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:16:54 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strtrim(const char *string)
{
	size_t	length;
	size_t	start;

	if (string != NULL)
	{
		start = 0;
		while (ft_isstdspace(string[start]))
			start++;
		length = ft_strlen(string + start);
		if (length > 0)
			while (ft_isstdspace(string[start + length - 1]))
				length--;
		return (ft_strsub(string, start, length));
	}
	return (NULL);
}
