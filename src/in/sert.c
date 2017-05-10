/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sert.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:53:59 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/09 16:15:56 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define LN in->ln[in->y]

void	in_sert(t_in *in, char *buff)
{
	if (in->x + 1 == LN.mem)
	{
		MGUARD(DRALT(LN.ln, /* ... */, LN.mem * 2));
		LN.mem *= 2;
	}
	LN.ln[in->x] = *buff;
	LN.len += 1;
	in->x += 1;
	in_meta_redraw(in);
}
