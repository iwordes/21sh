/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:08:36 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/10 16:05:59 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	in_delete(t_in *in)
{
	if (in->s != 0)
	{
		in_sel_del(in);
		in->s = 0;
		in_redraw(in);
	}
	else if (in->x > 0)
	{
		ft_strcut(in->ln[in->y].ln, in->x - 1, 1);
		in->ln[in->y].len -= 1;
		in->x -= 1;
		in_redraw(in);
	}
}
