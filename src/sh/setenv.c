/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:35:59 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 18:12:56 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	sh_setenv(char **argv, int argc)
{
	int		i;

	i = 0;
	while (++i < argc)
		if (ft_strchr(argv[i], '=') && !env_set(argv[i]))
			ft_eprintf("setenv: \e[91m%s\e[0m\n", argv[i]);
		else if (!env_set2(argv[i], ""))
			ft_eprintf("setenv: \e[91m%s\e[0m\n", argv[i]);
}
