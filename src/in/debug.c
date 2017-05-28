/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:30:18 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 15:36:55 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	in_debug(t_in *in)
{
	ft_dprintf(2, "-- DEBUG MODE --\n");
	in->ln[0].ps_len = 2;
	in->debug = !in->debug;
	if (in->debug)
		in->ln[0].ps = "\e[91m$ \e[0m";
	else
		in->ln[0].ps = "$ ";
	in_redraw(in);
}
