/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:44:37 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:16:06 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strmap(const char *string, char (*func)(char))
{
	size_t	i;
	char	*new_string;

	if (string != NULL && func != NULL)
	{
		i = 0;
		new_string = ft_strnew(ft_strlen(string));
		if (new_string != NULL)
			while (string[i] != 0)
			{
				new_string[i] = func(string[i]);
				i++;
			}
		return (new_string);
	}
	return (NULL);
}
