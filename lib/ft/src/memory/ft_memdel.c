/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:34 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:13:40 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Freeing NULL is defined behavior, doing absolutely nothing.
*/

void	ft_memdel(void **pointer)
{
	if (pointer != NULL)
	{
		free(*pointer);
		*pointer = NULL;
	}
}
