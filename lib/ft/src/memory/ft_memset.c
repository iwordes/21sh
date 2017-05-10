/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:38 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:13:44 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *memory, int value, size_t length)
{
	size_t	i;
	t_byte	*bytes;

	i = 0;
	bytes = (t_byte*)memory;
	while (i < length)
		bytes[i++] = (t_byte)value;
	return (memory);
}
