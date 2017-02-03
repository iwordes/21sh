/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:40:24 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/03 10:58:31 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_sh	g_sh;

int		main(void)
{
	char	*in;

	init_tty();
	while ((ft_printf("\e[92m$\e[0m ")) && (in = input()) != NULL)
	{
		write(1, "\n", 1);
		if (ft_strequ(in, "exit"))
			break ;
		ft_printf("%s\n", in);
		free(in);
	}
	free(in);
	uninit_tty();
	return (0);
}
