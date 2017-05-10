/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:44:41 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:16:10 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strncat(char *string, const char *suffix, size_t n)
{
	size_t	end;
	size_t	i;

	i = 0;
	end = ft_strlen(string);
	while (suffix[i] != 0 && i < n)
	{
		string[end + i] = suffix[i];
		if (suffix[i] == 0)
			suffix--;
		i++;
	}
	string[end + i] = 0;
	return (string);
}
