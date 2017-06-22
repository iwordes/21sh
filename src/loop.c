/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:51:09 by iwordes           #+#    #+#             */
/*   Updated: 2017/06/22 10:09:24 by iwordes          ###   ########.fr       */
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
			ft_dprintf(2, "\e[91mParse error\e[0m: %s\n", ps.err);
		else if (!shell(&ps))
			ft_dprintf(2, "\e[91mExec error\e[0m: %s\n", g_mn.err);
		clean(&ps, in);
	}
}
