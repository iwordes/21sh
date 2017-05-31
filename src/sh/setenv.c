/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:35:59 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/31 15:12:49 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	sh_setenv(char **argv, int argc)
{
	bool	o;
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strchr(argv[i], '='))
			o = env_set(argv[i]);
		else
			o = env_set2(argv[i], "");
		if (!o)
			ft_eprintf("setenv: \e[91m%s\e[0m\n", argv[i]);
	}
}
