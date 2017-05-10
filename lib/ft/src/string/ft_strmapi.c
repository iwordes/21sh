/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:44:39 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:16:09 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strmapi(const char *string, char (*func)(unsigned int, char))
{
	size_t	i;
	char	*new_string;
	size_t	string_length;

	if (string != NULL && func != NULL)
	{
		i = 0;
		string_length = ft_strlen(string);
		new_string = ft_strnew(string_length);
		if (new_string != NULL)
			while (i < string_length)
			{
				new_string[i] = func((unsigned)i, string[i]);
				i++;
			}
		return (new_string);
	}
	return (NULL);
}
