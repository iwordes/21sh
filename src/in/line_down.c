/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:37:37 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/10 19:27:11 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	in_line_down(t_in *in)
{
	if (in->len > 1)
	{
		if (in->y + 1 < in->len)
		{
			in->s = 0;
			in->y += 1;
			in->x = MIN(in->x, in->ln[in->y].len);
			in_redraw(in);
		}
	}
	else if (g_mn.hist_len > 0)
	{
		// ...
	}
}
