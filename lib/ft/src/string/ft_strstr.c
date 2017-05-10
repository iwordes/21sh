/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:45:04 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:16:50 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	needle_length;

	needle_length = ft_strlen(needle);
	if (needle_length == 0)
		return ((char*)haystack);
	while (*haystack != 0)
	{
		if (ft_strncmp(haystack, needle, needle_length) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
