/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:41:02 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/14 13:55:52 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Reprint the input buffer.
** Finally, relocate the cursor to its expected position.
*/

/*
** From a given t_in, find and navigate to the beginning cursor position of the
** input buffer, taking into account each line's length and prompt.
*/

/*
** How does this react if the user resizes the window between calls?
*/

#define LN (in->ln[i])

void	in_print(t_in *in)
{
	size_t	i;

	i = 0;
	tm_gotor(-g_sh.cx, -g_sh.cy);
	while (i < in->l)
	{
		write(1, LN.ps, LN.ps_len);
		if (i != in->y)
			write(1, LN.ln, LN.ln_len);
		else
		{
			write(1, LN.ln, in->x);
			tm_cur_save();
			write(1, LN.ln + in->x, LN.ln_len - in->x);
		}
		i += 1;
	}
	tm_clr_eos();
	tm_cur_rest();
}
