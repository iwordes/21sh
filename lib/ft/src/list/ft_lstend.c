/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:42:59 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:12:14 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Given a t_list list, non-destructively returns the last link of that list.
** - If the list is only one link long, returns the list immediately.
** - If the list is NULL, returns immediately.
*/

t_list		*ft_lstend(t_list *list)
{
	if (list != NULL)
		while (list->next != NULL)
			list = list->next;
	return (list);
}
