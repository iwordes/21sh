/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:44:17 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/31 08:47:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strdup(const char *original)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = ft_strnew(ft_strlen(original));
	if (copy != NULL)
		while (original[i])
		{
			copy[i] = original[i];
			i++;
		}
	return (copy);
}
