/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memuntil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:40:36 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:13:48 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Returns either *limit* or the index of the first instance of *find*.
*/

size_t	ft_memuntil(const void *memory, t_byte find, size_t limit)
{
	size_t	i;
	t_byte	*bytes;

	i = 0;
	bytes = (t_byte*)memory;
	while (i < limit && bytes[i] != find)
		i++;
	return (i);
}
