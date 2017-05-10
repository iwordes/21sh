/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:38:43 by iwordes           #+#    #+#             */
/*   Updated: 2016/11/16 16:41:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_lstdel(t_list **list, void (*del)(void*, size_t));
void				ft_lstdelone(t_list **list, void (*del)(void*, size_t));
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstiter(t_list *list, void (*f)(t_list*));
t_list				*ft_lstmap(t_list *list, t_list *(*f)(t_list*));

t_list				*ft_lstend(t_list *list);
void				ft_lstinsert(t_list *list, t_list *insert, size_t after);
size_t				ft_lstlen(const t_list *list);
t_list				*ft_lstn(t_list *list, size_t index);

void				ft_lstndel(t_list **list, void (*del)(void*, size_t),
							size_t index);
void				ft_lstndelone(t_list **list, void (*del)(void*, size_t),
							size_t index);

void				ft_lstpush(t_list *list, t_list *link);
t_list				*ft_lstpop(t_list *list);

void				ft_lstadd(t_list **list, t_list *link);
void				ft_lstunshift(t_list **list, t_list *link);
t_list				*ft_lstshift(t_list **list);

#endif
