/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:01:19 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/10 19:40:00 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define LN in->ln[in->y]

void	in_ctrl_x(t_in *in)
{
	if (in->s != 0)
	{
		in_hist_del(in);
		free(in->clip);
		if (in->s > 0)
			in->clip = ft_strsub(LN.ln, in->x, in->s);
		else
			in->clip = ft_strsub(LN.ln, in->x + in->s, -in->s);
		in_sel_del(in);
		in->s = 0;
		in_redraw(in);
	}
}
