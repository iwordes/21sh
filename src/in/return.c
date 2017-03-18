/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 13:30:51 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/18 11:47:08 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

// What happens when the user presses enter in a middle line?
// What happens when the user presses enter in the middle of a line?

#define LN (in->ln[in->y])

bool	in_return(t_in *in)
{
	t_inln	*tmp;

	//if (in->q == NULL)
	//	return (true);
	in->x = 0;
	in->y += 1;
	in->l += 1;
	if (in->l >= in->mem)
	{
		MGUARD(tmp = ZALT(t_inln, in->mem * 2));
		ft_memcpy(tmp, in->ln, sizeof(t_in) * in->mem);
		in->mem *= 2;
		free(in->ln);
		in->ln = tmp;
	}
	MGUARD(LN.ps = ft_strdup(in->ps2));
	MGUARD(LN.ln = ft_strnew(128));
	LN.ps_len = in->ps2_len;
	LN.mem = 128;
	in_print(in);
	in_goto(in, in->x, in->y);
	return (false);
}
