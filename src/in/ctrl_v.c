/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:02:14 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/10 11:34:26 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define LN in->ln[in->y]

void	in_ctrl_v(t_in *in)
{
	if (in->clip != NULL)
	{
		sel_del(in);
		ft_strins(LN.ln, in->clip, in->x);
		LN.len += ft_strlen(in->clip);
		in->x += ft_strlen(in->clip);
		in->s = 0;
		in_redraw(in);
	}
}
