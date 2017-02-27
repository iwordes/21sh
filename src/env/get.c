/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 18:49:02 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 18:53:30 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** NULL: Key not in table.
*/

char	*env_get(const char *env)
{
	size_t	i;

	i = ~0L;
	while (g_sh.env[i += 1] != NULL)
		if (kv_cmp(env, g_sh.env[i]))
			return (ft_strchr(g_sh.env[i], '=') + 1);
	return (NULL);
}
