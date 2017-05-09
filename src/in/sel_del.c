/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 10:15:45 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/18 10:24:55 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

bool	in_sel_del(t_in *in)
{
	if (in->sel != 0)
	{
		ft_strcut(LN.ln, in->x, in->sel);
		if (in->sel < 0)
			while (in->sel++)
				in_left(in);
		in->sel = 0;
		in_print();
	}
	return (false);
}
