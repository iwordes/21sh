/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 12:46:57 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 13:14:47 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

bool	env_set(const char *kv)
{
	uint32_t	i;

	i = ~0;
	while (++i < g_mn.env_len)
		if (env_cmp(kv, g_mn.env[i]))
		{
			free(g_mn.env[i]);
			return ((g_mn.env[i] = ft_strdup(kv)) != NULL);
		}
	env_grow(i + 1);
	if ((g_mn.env[i] = ft_strdup(kv)))
	{
		g_mn.env_len += 1;
		return (true);
	}
	return (false);
}
