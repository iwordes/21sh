/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 18:49:54 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/04 11:15:50 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** 0: Not set.
** 1: Updated.
** 2: Created.
*/

char	env_set(const char *env)
{
	size_t	i;

	i = ~0L;
	while (g_sh.env[i += 1] != NULL)
		if (kv_cmp(env, g_sh.env[i]))
		{
			free(g_sh.env[i]);
			if ((g_sh.env[i] = ft_strdup(env)) == NULL)
				return (0);
			break ;
		}
	if (g_sh.env[i] != NULL)
		return (1);
	env_grow(i);
	if ((g_sh.env[i] = ft_strdup(env)) == NULL)
		return (0);
	return (2);
}
