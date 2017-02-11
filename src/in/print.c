/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 12:40:58 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/07 19:39:23 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** This can be heavily optimized, but is also the easiest flexible
** implementation.
*/

void	in_print(t_in *in)
{
	t_2u64	i;

	tm_load();
	i.y = ~0L;
	while (in->ln[i.y += 1] != NULL)
	{
		ft_putstr((i.y == 0) ? in->ps1 : in->ps2);
		if (i.y != in->y)
			ft_putstr(in->ln[i.y]);
		else
		{
			write(1, in->ln[i.y], in->x);
			tm_cur_save();
			ft_putstr(in->ln[i.y] + in->x);
		}
		if (in->ln[i.y + 1] != NULL)
			write(1, "\n", 1);
	}
	tm_cur_load();
}
