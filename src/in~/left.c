/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:06:21 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/11 14:02:53 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	in_left(t_in *in)
{
	if (in->x > 0)
	{
		if (in->x > in->ln[in->y].ln_len)
			in->x = in->ln[in->y].ln_len);
		in->x -= 1;
		if ((in->ln[in->y].ps_len + in->x) % g_sh.cols == 0)
			tm_gotor(g_sh.cols, -1);
		else
		{
			if (ft_iscntrl(in->ln[in->y].ln[in->x]))
				tm_left();
			tm_left();
		}
	}
}
