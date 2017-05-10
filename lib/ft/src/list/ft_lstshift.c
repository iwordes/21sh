/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:20 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:12:52 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Given a t_list **list, detaches the first link from that list and returns a
** t_list* to it.
** - If given a NULL list, returns NULL.
** - If given a list of only a single link, returns that first link.
*/

t_list		*ft_lstshift(t_list **list)
{
	t_list	*link;

	if (list != NULL && *list != NULL)
	{
		link = *list;
		if ((*list)->next != NULL)
			*list = (*list)->next;
		link->next = NULL;
		return (link);
	}
	return (NULL);
}
