/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 12:40:58 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/11 19:24:02 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** This can be heavily optimized, but is also the easiest flexible
** implementation.
*/

static void		left_(t_in *in, t_2u32 *i)
{
	i->x -= 1;
	if ((in->ln[i->y].ps_len + i->x) % g_sh.cols == g_sh.cols - 1)
		tm_gotor(g_sh.cols, -1);
	else
	{
		if (ft_iscntrl(in->ln[i->y].ln[i->x]))
			tm_left();
		tm_left();
	}
}

static void		right_(t_in *in, t_2u32 *i)
{
	if ((in->ln[i->y].ps_len + i->x) % g_sh.cols == g_sh.cols - 1)
		tm_nextln();
	else
	{
		if (ft_iscntrl(in->ln[i->y].ln[i->x]))
			tm_right();
		tm_right();
	}
	i->x += 1;
}

void			in_print(t_in *in)
{
	t_2u32	i;

	tm_cur_load();
	tm_clr_eos();
	i.y = ~0L;
	while (in->ln[i.y += 1] != NULL)
	{
		ft_putstr(in->ln[i.y].ps);
		ft_putvis(in->ln[i.y].ln);
		if (in->ln[i.y + 1] != NULL)
			write(1, "\n", 1);
	}
	while (i.y != in->y)
	{
		i.x = ft_strlen(in->ln[i.y].ln);
		while (i.x > 0)
			left_(in, &i);
		tm_up();
		i.y -= 1;
	}
	while (i.x != in->x)
		right_(in, &i);
}
