/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:26 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:13:33 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*ft_memccpy(void *mdest, const void *msrc, int character, size_t n)
{
	t_byte	*dest;
	t_byte	*src;
	size_t	i;

	i = 0;
	src = (t_byte*)msrc;
	dest = (t_byte*)mdest;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == (t_byte)character)
			return ((void*)(dest + i + 1));
		i++;
	}
	return (NULL);
}
