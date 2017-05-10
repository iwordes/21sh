/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sert.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:53:59 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/10 13:12:59 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define LN in->ln[in->y]

void	in_sert(t_in *in, char *buff)
{
	if (in->s != 0)
	{
		// Erase selection
	}
	if (in->x + 1 == LN.mem)
	{
		MGUARD(DRALT(LN.ln, char, LN.mem * 2, LN.mem));
		LN.mem *= 2;
	}
	LN.ln[in->x] = *buff;
	LN.len += 1;
	in->x += 1;
	in_redraw(in);
}
