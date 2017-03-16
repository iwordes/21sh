/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:33:12 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/16 14:14:26 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

bool	in_right(t_in *in)
{
	if (in->x == in->ln[in->y].ln_len)
		return (false);
	sh_right();
	in->x += 1;
	ft_eprintf("R -> [%d,%d]\n", g_sh.cx, g_sh.cy);
	return (false);
}
