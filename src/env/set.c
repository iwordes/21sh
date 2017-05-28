/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 12:46:57 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 18:10:09 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

bool	env_set(const char *kv)
{
	uint32_t	i;

	ft_printf("\e[95menv_set\e[0m(\e[92m\"%s\"\e[0m)\n", kv);

	i = ~0;
	while (++i < g_mn.env_len)
		if (env_cmp(kv, g_mn.env[i]))
		{
			ft_printf("\e[92menv_set\e[0m\n", kv);
			free(g_mn.env[i]);
			return ((g_mn.env[i] = ft_strdup(kv)) != NULL);
		}

	env_grow(i);
	if ((g_mn.env[i] = ft_strdup(kv)))
	{
		ft_printf("\e[96menv_set\e[0m\n", kv);
		g_mn.env_len += 1;
		return (true);
	}

	ft_printf("\e[91menv_set\e[0m\n", kv);
	return (false);
}
