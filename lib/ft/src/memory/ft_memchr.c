/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:28 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:13:31 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*ft_memchr(const void *memory, int find, size_t bytecount)
{
	size_t	i;
	t_byte	*bytes;

	i = 0;
	bytes = (t_byte*)memory;
	while (i < bytecount)
	{
		if (bytes[i] == (t_byte)find)
			return ((void*)(bytes + i));
		i++;
	}
	return (NULL);
}
