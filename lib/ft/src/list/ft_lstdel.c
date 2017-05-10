/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:42:55 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:12:08 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Given a t_list** list, frees all links in that list and sets the original
** pointer to NULL.
** - If the given list is already NULL, finishes immediately.
** - free DOES NOT work on lists created on the stack.
*/

void	ft_lstdel(t_list **list, void (*del)(void*, size_t))
{
	t_list	*next_link;

	if (list != NULL && del != NULL)
		while (*list != NULL)
		{
			next_link = (*list)->next;
			del((*list)->content, (*list)->content_size);
			free(*list);
			*list = next_link;
		}
}
