/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:11:13 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/04 10:13:44 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static void	default_env_(void)
{
	env_set("PS1=\e[91m$\e[0m ");
	env_set("PS2=\e[93m.\e[0m ");
}

void		init_env(void)
{
	extern char	**environ;
	size_t		i;

	MGUARD(g_sh.env = (char**)ft_memalloc(sizeof(char*) * (ENV_LEN + 1)));
	g_sh.env_len = ENV_LEN;
	i = ~0L;
	while (environ[i += 1] != NULL)
	{
		env_grow(i);
		if (ft_strchr(environ[i], '=') != NULL)
			g_sh.env[i] = ft_strdup(environ[i]);
		else
			g_sh.env[i] = ft_strjoin(environ[i], "=");
		MGUARD(g_sh.env[i]);
	}
	default_env_();
}
