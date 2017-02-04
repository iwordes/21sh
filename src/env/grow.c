/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 09:54:46 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/04 09:55:55 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	env_grow(size_t i)
{
	char	**env;
	size_t	l;

	if (i < g_sh.env_len)
		return ;
	l = g_sh.env_len;
	while (i >= l)
		l *= 2;
	MGUARD(env = ft_memalloc(sizeof(char*) * (l + 1)));
	i = ~0L;
	while (g_sh.env[i += 1] != NULL)
		env[i] = g_sh.env[i];
	free(g_sh.env);
	g_sh.env = env;
	g_sh.env_len = l;
}
