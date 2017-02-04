/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 09:44:43 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/04 09:52:02 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

bool	env_del(const char *env)
{
	size_t	i;

	i = ~0;
	while (g_sh.env[i += 1] != NULL)
		if (kv_cmp(g_sh.env[i], env))
		{
			free(g_sh.env[i]);
			while (g_sh.env[i += 1] != NULL)
				g_sh.env[i - 1] = g_sh.env[i];
			g_sh.env[i - 1] = NULL;
			return (true);
		}
	return (false);
}
