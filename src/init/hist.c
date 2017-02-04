/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:12:13 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/03 19:53:48 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Load terminal history from file, if available.
**
** Don't set HIST_LEN to 0.
*/

void	init_hist(void)
{
	int		fd;
	size_t	i;

	MGUARD(g_sh.hist = ft_memalloc(sizeof(char*) * (HIST_LEN + 1)));
	g_sh.hist_len = HIST_LEN;
	if ((fd = open("~/.21sh_history", O_RDONLY)) < 0)
		return ;
	i = 0;
	while (ft_readln(fd, g_sh.hist + i) > 0)
		hist_grow(i += 1);
	free(g_sh.hist[i]);
	g_sh.hist[i] = NULL;
	close(fd);
}
