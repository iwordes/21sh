/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:18 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:12:50 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Given a t_list* list and a t_list* link, appends the link to the end of the
** list.
*/

void	ft_lstpush(t_list *list, t_list *link)
{
	t_list	*last_link;

	if (list != NULL && link != NULL)
	{
		last_link = ft_lstend(list);
		last_link->next = link;
	}
}
