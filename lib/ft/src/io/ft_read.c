/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:38:45 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/21 14:59:10 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Read the entire contents of a file descriptor, byte-for-byte.
** NOTE: Current iteration cannot be expected to handle binary files.
**
** Returns NULL if allocation failed at any time during reading.
*/

static bool	grow_(char **file, size_t *m)
{
	char	*tmp;

	if ((tmp = MALT(char, *m * 2 + 1)) == NULL)
		return (false);
	ft_memcpy(tmp, *file, *m);
	free(*file);
	*file = tmp;
	*m *= 2;
	return (true);
}

char		*ft_read(int fd)
{
	char	buff[4096];
	char	*file;
	size_t	l;
	size_t	m;
	ssize_t	r;

	l = 0;
	m = 4096;
	NULL_GUARD(file = MALT(char, 4096));
	while ((r = read(fd, buff, 4096)) > 0)
	{
		if (l + r > m && !grow_(&file, &m))
			return (NULL);
		ft_memcpy(file + l, buff, r);
		l += r;
	}
	file[l] = 0;
	return (file);
}
