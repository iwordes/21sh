/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:24 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:13:29 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*ft_memalloc(size_t size)
{
	void	*memory;

	memory = malloc(size);
	if (memory != NULL)
		ft_bzero(memory, size);
	return (memory);
}
