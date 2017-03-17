/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 21:40:33 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/17 14:01:54 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Navigate to the start of the current line.
*/

#define LN (in->ln[in->y])

bool	in_sol(t_in *in)
{
	while (in->x > 0)
		in_left(in);
	return (false);
}
