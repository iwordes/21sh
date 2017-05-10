/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:32 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/27 14:01:02 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*ft_memcpy(void *dest, const void *src, size_t l)
{
	size_t	i;

	i = 0;
	while (l - i >= 8)
	{
		*(uint64_t*)((char*)dest + i) = *(uint64_t*)((char*)src + i);
		i += 8;
	}
	while (i < l)
	{
		((char*)dest)[i] = ((char*)src)[i];
		i += 1;
	}
	return (dest);
}
