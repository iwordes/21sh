/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:01:14 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/18 10:19:51 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Safely move the cursor left one character, wrapping back across lines.
*/

bool	in_left(t_in *in)
{
	if (in->x == 0)
		return (false);
	sh_left();
	in->x -= 1;
	return (false);
}
