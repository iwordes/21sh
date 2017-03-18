/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:13:43 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/18 15:35:10 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Save terminal history to file.
** Unfortunately, the required function to do this properly is unavailable.
*/

void	uninit_hist(void)
{
	size_t	i;

	i = ~0L;
	while (g_sh.hist[i += 1] != NULL)
		free(g_sh.hist[i]);
	free(g_sh.hist);
}
