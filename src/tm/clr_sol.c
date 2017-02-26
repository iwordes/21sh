/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_sol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 13:27:47 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/05 13:29:28 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtm.h>

/*
** Clear the screen from the beginning of the current line to the cursor.
*/

void	tm_clr_sol(void)
{
	tm_putstr(TM_CLR_SOL);
}
