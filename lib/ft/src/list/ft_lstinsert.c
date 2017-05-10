/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:01 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:12:27 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Given a t_list* list, a t_list* insert, and a size_t n, inserts the second
** list after the given index in the list.
** - n is an index from 0 onward.
** - If the value of n is at either end of the list, it pre- or appends insert.
*/

void		ft_lstinsert(t_list *list, t_list *insert, size_t n)
{
	if (list != NULL && insert != NULL)
	{
		list = ft_lstn(list, n);
		ft_lstend(insert)->next = list->next;
		list->next = insert;
	}
}
