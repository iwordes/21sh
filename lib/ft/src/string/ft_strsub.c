/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:45:06 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:16:52 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(const char *string, unsigned int start, size_t length)
{
	char	*substring;

	if (string != NULL)
	{
		substring = ft_strnew(length);
		if (substring != NULL)
			ft_strncat(substring, string + start, length);
		return (substring);
	}
	return (NULL);
}
