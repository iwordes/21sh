/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:50:16 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 13:25:51 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	sh_echo(char **argv, int argc)
{
	bool	nl;
	int		i;

	i = 1;
	nl = true;
	if (argc > 1 && ft_strequ(argv[1], "-n"))
	{
		nl = false;
		i += 1;
	}
	while (i < argc)
	{
		if (i > 1)
			write(1, " ", 1);
		ft_putstr(argv[i]);
		i += 1;
	}
	if (nl)
		write(1, "\n", 1);
}
