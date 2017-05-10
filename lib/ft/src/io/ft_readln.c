/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readln.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:58:37 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/16 17:46:14 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Read one line of text from a non-binary file descriptor.
** Return (1) if a line was read.
** Return (0) if EOF has been reached.
** Return (-1) on error.
*/
/*
** TODO: Refactor, expand, and make this more readable.
*/

static void		ft_readln_body(t_getln *getln, char **const line,
								size_t cache_size, size_t *total)
{
	char			*offset_buffer;
	size_t			next;

	*total = 0;
	while (TRUE)
	{
		if (getln->index == 0)
			if ((getln->limit = read(getln->fd, getln->buffer, 4096)) <= 0)
				break ;
		offset_buffer = getln->buffer + getln->index;
		next = ft_memuntil(offset_buffer, '\n', getln->limit - getln->index);
		while (*total + next + 1 >= cache_size)
			if ((*line = ft_drealloc(*line, (cache_size *= 2), *total)) == NULL)
				break ;
		ft_memcpy(*line + *total, offset_buffer, next);
		*total += next;
		getln->index += next + 1;
		if (getln->index - 1 >= getln->limit)
			getln->index = 0;
		else if (getln->buffer[getln->index - 1] == '\n')
			break ;
	}
	if (*total > 0 && *line != NULL)
		(*line)[*total] = 0;
}

int				ft_readln(const int fd, char **const line)
{
	static t_getln	head;
	t_getln			*current;
	size_t			total;

	if (fd < 0 || line == NULL)
		return (-1);
	current = &head;
	*line = ft_strnew(0);
	while (current->fd != fd && current->next != NULL)
		current = current->next;
	if (current->fd != fd)
	{
		current->next = ft_memalloc(sizeof(t_getln));
		current = current->next;
		current->fd = fd;
	}
	ft_readln_body(current, line, 1, &total);
	if (current->limit >= 0 && *line != NULL)
		return (current->limit > 0);
	else
		return (-1);
}
