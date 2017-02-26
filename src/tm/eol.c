/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 15:09:59 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/06 13:06:16 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtm.h>

/*
** Move to the end of the current line.
**
** If you already know the number of columns in the current terminal, it's more
** efficient to do this yourself.
**
** Opt: Use "\e[%dG" to move immediately to the EOL.
*/

void	tm_eol(void)
{
	int		cols;
	int		i;

	i = 1;
	tm_sol();
	cols = tm_cols();
	while (i++ < cols)
		tm_right();
}
