/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:06:13 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 13:42:07 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static void	load_env(void)
{
	extern char	**environ;
	uint32_t	i;

	i = ~0;
	g_mn.env_mem = 128;
	MGUARD(g_mn.env = ZALT(char*, 128));
	while (environ[i += 1] != NULL)
	{
		if (!env_grow(i))
			exit(1);
		if (ft_strchr(environ[i], '=') != NULL)
			g_mn.env[i] = ft_strdup(environ[i]);
		else
			g_mn.env[i] = ft_strjoin(environ[i], "=");
		MGUARD(g_mn.env[i]);
	}
	g_mn.env_len = i;
}

void		init_env(void)
{
	load_env();
	env_set("PS1=$ ");
	env_set("PS2=: ");
}
