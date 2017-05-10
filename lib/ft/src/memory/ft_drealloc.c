/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drealloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:54:16 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:26:11 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Similar to realloc, but frees the input pointer if allocation fails.
*/

void	*ft_drealloc(void *original, size_t target_size, size_t original_size)
{
	void	*copy;

	copy = ft_realloc(original, target_size, original_size);
	if (copy == NULL)
		free(original);
	return (copy);
}
