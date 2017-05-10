/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:43:15 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:12:45 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Create a new link of a linked list and initialize it to a usable state.
*/

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*link;

	link = (t_list*)malloc(sizeof(t_list));
	if (link != NULL)
	{
		link->content = NULL;
		link->content_size = 0;
		if (content != NULL)
		{
			link->content = malloc(content_size);
			if (link->content != NULL)
			{
				ft_memcpy(link->content, content, content_size);
				link->content_size = content_size;
			}
		}
		link->next = NULL;
	}
	return (link);
}
