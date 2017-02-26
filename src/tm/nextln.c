/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nextln.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 13:08:02 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/05 15:53:53 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtm.h>

/*
** Move to the beginning of the next line.
*/

void	tm_nextln(void)
{
	tm_putstr("\e[E");
}
