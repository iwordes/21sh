/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:13:43 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/03 19:57:35 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Save terminal history to file.
*/

void	uninit_hist(void)
{
	int		fd;
	size_t	i;

	if ((fd = open("~/.21sh_history", O_WRONLY | O_CREAT | O_TRUNC)) >= 0)
	{
		i = ~0L;
		while (g_sh.hist[i += 1] != NULL)
		{
			write(fd, g_sh.hist[i], ft_strlen(g_sh.hist[i]));
			write(fd, "\n", 1);
		}
		close(fd);
	}
	free(g_sh.hist);
}
