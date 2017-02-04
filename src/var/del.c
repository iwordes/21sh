/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 10:21:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/04 11:16:37 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

bool	var_del(const char *var)
{
	size_t	i;

	i = ~0L;
	while (g_sh.var[i += 1] != NULL)
		if (kv_cmp(g_sh.var[i], var))
		{
			free(g_sh.var[i]);
			while (g_sh.var[i += 1] != NULL)
				g_sh.var[i - 1] = g_sh.var[i];
			g_sh.var[i - 1] = NULL;
			return (1);
		}
	return (env_del(var));
}
