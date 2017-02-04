/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:16:47 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/04 11:20:09 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	hist_grow(size_t i)
{
	char	**hist;
	size_t	l;

	if (i < g_sh.hist_len)
		return ;
	l = g_sh.env_len;
	while (i >= l)
		l *= 2;
	MGUARD(hist = ft_memalloc(sizeof(char*) * (l + 1)));
	i = ~0L;
	while (g_sh.hist[i += 1] != NULL)
		hist[i] = g_sh.hist[i];
	free(g_sh.hist);
	g_sh.hist = hist;
	g_sh.hist_len = l;
}
