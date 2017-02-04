/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 18:49:02 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/04 10:12:01 by iwordes          ###   ########.fr       */
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
		if (kv_cmp(g_sh.env[i], env))
			return (ft_strchr(g_sh.env[i], '=') + 1);
	return (NULL);
}
