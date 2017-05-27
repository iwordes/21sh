/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 12:49:15 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 13:52:16 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

bool	env_grow(uint32_t i)
{
	char		**tmp;
	uint32_t	mem;

	if (i + 1 >= g_mn.env_mem)
	{
		mem = g_mn.env_mem;
		while (i + 1 >= mem)
			mem *= 2;
		if ((tmp = ZALT(char*, mem)) == NULL)
			return (false);
		ft_memcpy(tmp, g_mn.env, g_mn.env_mem * sizeof(char*));
		g_mn.env_mem = mem;
		free(g_mn.env);
		g_mn.env = tmp;
	}
	return (true);
}
