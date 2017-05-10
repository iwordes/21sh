/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:53:52 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:12:17 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Locates a particular piece of data within a list.
*/

t_list	*ft_lstfind(t_list *list, void *data, int (*cmp)(void*, void*))
{
	if (list != NULL & cmp != NULL)
	{
		while (list)
		{
			if (cmp(data, list->content) == 0)
				return (list);
			list = list->next;
		}
	}
	return (NULL);
}
