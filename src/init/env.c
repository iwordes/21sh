/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:06:13 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/09 20:30:23 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static void	load_env(void)
{
	extern char	**environ;

	i = ~0;
	g_mn.env_mem = 128;
	MGUARD(g_mn.env = ZALT(char*, 128));
	while (environ[i += 1] != NULL)
	{
		env_grow(i);
		if (ft_strchr(environ[i], '=') != NULL)
			g_mn.env[i] = ft_strdup(environ[i]);
		else
			g_mn.env[i] = ft_strjoin(environ[i], "=");
		MGUARD(g_mn.env[i]);
	}
}

void		init_env(void)
{
	load_env();
	env_set("PS1=$ ");
	env_set("PS2=: ");
	env_set("PS4=+ ");
}
