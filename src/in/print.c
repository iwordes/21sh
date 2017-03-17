/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:41:02 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/17 12:51:50 by iwordes          ###   ########.fr       */
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
#define X (c % g_sh.cols)
#define Y (c / g_sh.cols)

void	in_print(t_in *in)
{
	size_t	i;
	int		c;

	i = 0;
	c = 0;
	tm_gotor(-g_sh.cx, -g_sh.cy);
	while (i < in->l)
	{
		ft_putstr("\e[92m");
		write(1, LN.ps, 1);
		ft_putstr("\e[0m");
		write(1, LN.ps + 1, LN.ps_len - 1);
		//write(1, LN.ps, LN.ps_len);
		write(1, LN.ln, LN.ln_len);
		ft_eprintf("c (%d) += %jd + %jd\n", c, LN.ps_len, LN.ln_len);
		c += LN.ps_len + LN.ln_len;
		tm_clr_eos();
		if (i + 1 < in->l)
		{
			write(1, "\n", 1);
			c += (g_sh.cols - X);
		}
		i += 1;
	}
	ft_putstr("\e[91mX\e[0m\e[D");
	tm_gotor(g_sh.cx - X, g_sh.cy - Y);
}
