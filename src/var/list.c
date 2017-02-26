/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:53:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/25 12:23:21 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	var_list(void)
{
	size_t	i;
	size_t	l;

	i = ~0L;
	while (g_sh.var[i += 1] != NULL)
	{
		l = ft_struntil(g_sh.var[i], '=');
		ft_printf("\e[1m%.*s\e[0m='%s'\n", l, g_sh.var[i],
			g_sh.var[i] + l + 1);
	}
}
