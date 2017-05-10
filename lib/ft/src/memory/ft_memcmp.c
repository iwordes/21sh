/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:30 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:13:35 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_memcmp(const void *mem1, const void *mem2, size_t bytecount)
{
	size_t	i;
	t_byte	*bytes1;
	t_byte	*bytes2;

	i = 0;
	bytes1 = (t_byte*)mem1;
	bytes2 = (t_byte*)mem2;
	while (i < bytecount)
	{
		if (bytes1[i] != bytes2[i])
			return (bytes1[i] - bytes2[i]);
		i++;
	}
	return (0);
}
