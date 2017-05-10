/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:53:45 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:09:31 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** ft_getline()
** ==========
** ## Synopsis:
** Obtains one line from the given file descriptor, ending in NUL.
** Subsequent calls with the same file descriptor will grant new lines.
** On allocation failure, *line will be NULL.
**
** ## Explanation:
**
** As far as the user goes, ft_getline takes an int and a char**. The constness
** of ft_getline()'s arguments is mainly for internal documentation reasons.
*/

/*
** NOTE: Will encounter issues when reading files with lines longer than
** SSIZE_T_MAX. This is a shortcoming of the mandatory negative signaling
** mechanism.
*/

#include <ft_io.h>

static void		ft_getline_body(t_getln *getln, char **const line,
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

ssize_t			ft_getline(const int fd, char **const line)
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
	ft_getline_body(current, line, 1, &total);
	if (current->limit >= 0 && *line != NULL)
		return (total);
	else
		return (-1);
}
