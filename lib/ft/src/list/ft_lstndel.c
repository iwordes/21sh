/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstndel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:11 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:12:40 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Given a t_list* list and a size_t index n, detaches and deletes all links
** after index N.
*/

void		ft_lstndel(t_list **list, void (*del)(void*, size_t), size_t n)
{
	t_list	*temp;

	if (list != NULL && *list != NULL && del != NULL)
	{
		if (n == 0)
			ft_lstdel(list, del);
		else
		{
			temp = ft_lstn(*list, n + 1);
			ft_lstdel(&temp, del);
		}
	}
}
