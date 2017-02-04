/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:32:49 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/03 19:40:16 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	var_grow(size_t i)
{
	char	**var;
	size_t	l;

	if (i < g_sh.var_len)
		return ;
	l = g_sh.var_len;
	while (i >= l)
		l *= 2;
	MGUARD(var = ft_memalloc(sizeof(char*) * (l + 1)));
	i = ~0L;
	while (g_sh.var[i += 1] != NULL)
		var[i] = g_sh.var[i];
	free(g_sh.var);
	g_sh.var = var;
	g_sh.var_len = l;
}
