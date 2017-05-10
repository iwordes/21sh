/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:49:14 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/09 16:53:34 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

/*
** IDEA: Terminal library with internal position management
*/

void	tm_goto(int16_t x, int16_t y)
{
	g_mn.x += x;
	g_mn.y += y;
	while (x > 0)
	{
		write(1, "\e[C", 3);
		x -= 1;
	}
	while (x < 0)
	{
		write(1, "\e[D", 3);
		x += 1;
	}
	while (y > 0)
	{
		write(1, "\e[B", 3);
		y -= 1;
	}
	while (y < 0)
	{
		write(1, "\e[A", 3);
		y += 1;
	}
}
