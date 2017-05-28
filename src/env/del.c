/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 12:53:29 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 18:15:20 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	env_del(const char *key)
{
	uint32_t	i;

	i = ~0;
	while (++i < g_mn.env_len)
		if (env_cmp(key, g_mn.env[i]))
		{
			free(g_mn.env[i]);
			ft_memcpy(g_mn.env + i, g_mn.env + i + 1,
				(g_mn.env_len - i) * sizeof(char*));
			g_mn.env[g_mn.env_len--] = NULL;
			return ;
		}
}
