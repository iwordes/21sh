/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:54:42 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/17 14:42:34 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	tm_left(void)
{
	if (g_mn.x != 0)
	{
		write(1, "\e[D", 3);
		g_mn.x -= 1;
	}
	else if (g_mn.y != 0)
	{
		write(1, "\e[F", 3);
		g_mn.y -= 1;
		g_mn.x = ~0;
		while (++g_mn.x < W)
			write(1, "\e[C", 3);
	}
}
