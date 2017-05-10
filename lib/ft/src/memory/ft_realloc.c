/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:54:14 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/18 13:46:29 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*ft_realloc(void *mem, size_t tgt, size_t orig)
{
	void	*copy;

	if (tgt == orig)
		return (mem);
	NULL_GUARD(copy = malloc(tgt));
	if (mem != NULL && copy != NULL)
		ft_memcpy(copy, mem, ft_lesser(tgt, orig));
	return (copy);
}
