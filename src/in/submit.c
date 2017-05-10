/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:15:28 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/09 19:38:12 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

/*
** TODO: Line Insertion
*/

void	in_submit(t_in *in)
{
	if (/* test_parse(in) */)
		in->submit = true;
	else if (in->y + 1 == in->len)
	{
		if (in->len == in->mem)
			// Grow
		in->y += 1;
		in->x = 0;
		in_redraw(in);
	}
}
