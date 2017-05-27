/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:52:59 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 10:43:09 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	sh_env(char **argv, int argc)
{
	int		i;

	if (argc == 1)
	{
		i = ~0;
		while (g_mn.env[++i])
			ft_printf("%s\n", g_mn.env[i]);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (env_get(argv[i]) == NULL)
				ft_printf("env: No such key: %s\n", argv[i]);
			else
				ft_printf("%s=%s\n", argv[i], env_get(argv[i]));
			i += 1;
		}
	}
}
