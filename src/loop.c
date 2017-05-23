/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:51:09 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/22 15:19:26 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	loop(void)
{
	char	*in;
	t_ps	ps;

	while ((in = input()))
	{
		if (!parse(&ps, in))
			ft_printf("\e[91mParse error\e[0m: %s\n", ps.err);
		else
			/*shell(&ps)*/;
		///
		write(1, "\n", 1);
		///
		clean(&ps, in);
	}
}
