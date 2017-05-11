/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 20:01:32 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/10 20:55:19 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define E(M...) ft_dprintf(2, M)

void	in_hist_add(t_in *in)
{
	if (g_mn.hist_len == g_mn.hist_mem)
	{
		MGUARD(DRALT(g_mn.hist, char*, g_mn.hist_mem * 2, g_mn.hist_mem));
		g_mn.hist_mem *= 2;
	}
	if ((g_mn.hist[g_mn.hist_len] = ft_strdup(in->line)) != NULL)
		g_mn.hist_len += 1;
}
