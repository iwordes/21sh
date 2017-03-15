/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 21:39:02 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/15 13:49:44 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Delete one character where the cursor is currently at.
*/

bool	in_del(t_in *in)
{
	if (in->x == 0)
		return (false);
	ft_strcut(in->ln[in->y].ln, in->x - 1, 1);
	in->ln[in->y].ln_len -= 1;
	in_print(in);
	if (in->x < in->ln[in->y].ln_len)
		in_left(in);
	else
		in->x -= 1;
	return (false);
}
