/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:24:05 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/09 20:38:28 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

/*
** TODO: Intuitive Up/Down (Not Like Vim)
*/

void	in_line_up(t_in *in)
{
	if (in->y > 0)
	{
		in->s = 0;
		in->y -= 1;
		in->x = MIN(in->x, in->ln[in->y].len);
		in_redraw(in);
	}
}
