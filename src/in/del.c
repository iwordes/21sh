/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 21:39:02 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/14 13:26:18 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Delete one character where the cursor is currently at.
*/

bool	del(t_in *in)
{
	ft_strcut(in->ln[in->y].ln, in->x, 1);
	in_print(in);
	in_left(in);
	return (false);
}
