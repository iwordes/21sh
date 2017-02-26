/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gotor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 13:21:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/05 16:01:07 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtm.h>

/*
** Go to a coordinate relative to the current cursor position.
*/

void	tm_rgoto(int x, int y)
{
	if (x < 0)
		while (x++)
			tm_left();
	else
		while (x--)
			tm_right();
	if (y < 0)
		while (y++)
			tm_down();
	else
		while (y--)
			tm_up();
}
