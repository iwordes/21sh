/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstndelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:13 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:12:43 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Given a t_list* list and a size_t index n, detaches the element at index n
** from the list and deletes it. The original pointer is updated if necessary.
** - If the given list is not long enough, it deletes the last link in the list.
** - If the given value for n is zero,
*/

void	ft_lstndelone(t_list **list, void (*del)(void*, size_t), size_t n)
{
	t_list	*temp_parent;
	t_list	*temp;

	if (list != NULL && *list != NULL && del != NULL)
	{
		if (n == 0)
		{
			temp = (*list)->next;
			ft_lstdelone(list, del);
			*list = temp;
		}
		else if ((*list)->next != NULL)
		{
			temp_parent = ft_lstn(*list, n - 1);
			temp = temp_parent->next;
			temp_parent->next = temp->next;
			ft_lstdelone(&temp, del);
		}
	}
}
