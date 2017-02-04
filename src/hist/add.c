/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:32:25 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/04 11:01:05 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	hist_add(const char *line)
{
	size_t	i;

	if (line[0] == ' ')
		return ;
	i = 0;
	while (g_sh.hist[i] != NULL)
		i += 1;
	hist_grow(i);
	g_sh.hist[i] = ft_strdup(line);
}
