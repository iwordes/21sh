/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:11:13 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/05 12:36:40 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static void	update_shlvl_(void)
{
	char	*shlvl;

	if ((shlvl = env_get("SHLVL")) != NULL)
	{
		shlvl = ft_itoa(ft_atoi(shlvl) + 1);
		env_setkey("SHLVL", shlvl);
		free(shlvl);
	}
}

static void	default_env_(void)
{
	update_pwd();
	env_del("OLDPWD");
	env_set("PS1=$ ");
	env_set("PS2=> ");
	env_set("PS4=+ ");
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
