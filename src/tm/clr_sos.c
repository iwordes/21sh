/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_sos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 13:25:05 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/05 13:27:40 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtm.h>

/*
** Clear the display from the start of the screen to the current cursor.
*/

void	tm_clr_sos(void)
{
	tm_putstr(TM_CLR_SOS);
}
