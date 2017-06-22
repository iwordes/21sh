/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:31:14 by iwordes           #+#    #+#             */
/*   Updated: 2017/06/22 10:08:34 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

/*
** 1. Init the main struct.
** 2. Create space for history.
** 3. Create a copy of the environment.
** 4. Backup and modify a copy of the terminal settings.
*/

void	init(void)
{
	bzero(&g_mn, sizeof(t_main));
	init_hist();
	init_env();
	init_sig();
	init_tty();
}
