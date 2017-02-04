/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:40:24 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/04 11:29:38 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_sh	g_sh;

int		main(void)
{
	char	*in;

	init();
	shell();
	while ((ft_printf("\e[92m$\e[0m ")) && (in = input()) != NULL)
	{
		if (ft_strequ(in, "exit"))
			return (0);
		write(1, "\n", 1);
		ft_printf("%s\n", in);
		free(in);
	}
	ft_putstr("exit\n");
	free(in);
	uninit();
	return (0);
}
