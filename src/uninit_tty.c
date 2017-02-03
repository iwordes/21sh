/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uninit_tty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:57:52 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/02 19:06:43 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	uninit_tty(void)
{
	while (tcsetattr(0, TCSANOW, &g_sh.tm_cfg_) == -1)
		;
}
