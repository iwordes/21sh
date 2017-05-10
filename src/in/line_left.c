/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:23:01 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/09 20:36:41 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	in_left(t_in *in)
{
	if (in->x > 0)
	{
		in->x -= 1;
		if (in->s == 0)
			tm_left();
		else
		{
			in->s = 0;
			in_redraw(in);
		}
	}
}