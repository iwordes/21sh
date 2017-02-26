/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prevln.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 13:13:43 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/05 15:54:33 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtm.h>

/*
** Move the cursor to the start of the previous line.
*/

void	tm_prevln(void)
{
	tm_putstr("\e[F");
}
