/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:57:55 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:12:48 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Given a t_list*, detaches the last link from the list and returns a t_list*
** to it.
** - If the given list is NULL, returns NULL.
** - If the given list has only one link, returns that link.
*/

t_list			*ft_lstpop(t_list *list)
{
	t_list		*second_last_link;
	t_list		*last_link;

	NULL_GUARD(list);
	last_link = list;
	second_last_link = list;
	while (last_link->next != NULL)
	{
		second_last_link = last_link;
		last_link = last_link->next;
	}
	second_last_link->next = NULL;
	return (last_link);
}
