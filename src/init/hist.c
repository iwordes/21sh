/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 20:27:32 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/10 20:28:48 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	init_hist(void)
{
	MGUARD(g_mn.hist = MALT(char*, 128));
	g_mn.hist_mem = 128;
}
