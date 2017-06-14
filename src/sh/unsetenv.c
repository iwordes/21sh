/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:36:22 by iwordes           #+#    #+#             */
/*   Updated: 2017/06/13 20:13:31 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	sh_unsetenv(char **argv, int argc)
{
	int		i;

	i = 0;
	if (argc == 1)
		ft_puterr("unsetenv: No arguments given.\n");
	while (++i < argc)
		env_del(argv[i]);
}
