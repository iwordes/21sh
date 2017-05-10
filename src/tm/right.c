/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:40:18 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/09 17:46:30 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	tm_right(void)
{
	if (g_mn.x != g_mn.w - 1)
	{
		write(1, "\e[C", 3);
		g_mn.x += 1;
	}
	else
	{
		write(1, "\e[E", 3);
		g_mn.y += 1;
		g_mn.x = 0;
	}
}
