/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:36 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/27 14:01:35 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Performs a non-destructive copy of n bytes from memory_src to memory_dest.
*/

void				*ft_memmove(void *dest, const void *src, size_t l)
{
	size_t	i;

	if (dest < src)
		return (ft_memcpy(dest, src, l));
	else
	{
		i = 0;
		while (l - i >= 8)
		{
			i += 8;
			*(uint64_t*)((char*)dest - i) = *(uint64_t*)((char*)src - i);
		}
		while (i < l)
		{
			i += 1;
			*((char*)dest - i) = *((char*)src - i);
		}
		*((char*)dest) = *((char*)src);
		return (dest);
	}
}
