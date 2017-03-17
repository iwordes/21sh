/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 21:39:02 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/16 15:25:53 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Delete one character where the cursor is currently at.
*/

#define LN (in->ln[in->y])

bool	in_del(t_in *in)
{
	if (in->x == 0)
		return (false);
	ft_strcut(LN.ln, in->x -= 1, 1);
	LN.ln_len -= 1;
	in_print(in);
	sh_left();
	return (false);
}
