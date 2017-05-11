/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drealloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:54:16 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/10 21:12:49 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_drealloc(void *original, size_t target_size, size_t original_size)
{
	void	*copy;

	copy = ft_realloc(original, target_size, original_size);
	free(original);
	return (copy);
}
