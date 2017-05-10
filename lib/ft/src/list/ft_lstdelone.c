/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:42:57 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:12:11 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Given a t_list** link, deletes that link, then sets the original t_list* to
** NULL.
** - Passing in a pointer to a list not created with malloc in some form will
**   result in undefined behavior!
*/

void	ft_lstdelone(t_list **link, void (*del)(void*, size_t))
{
	if (*link != NULL && del != NULL)
	{
		del((*link)->content, (*link)->content_size);
		free(*link);
		*link = NULL;
	}
}
