/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eoi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:41:53 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/11 14:24:43 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Go to the end of the last input string.
**
** Depends on a fully-zeroed t_in terminator.
*/

void	in_eoi(t_in *in)
{
	size_t	i;

	while (in->ln[in->y]->ln != NULL)
	{
		while (in->ln[in->y]->ln[in->x] != 0)
			in_right(in);
		tm_nextln();
		in->y += 1;
		in->x = 0;
		i = 0;
		while (i < in->ln[in->y].ps_len)
		{
			tm_right();
			i += 1;
		}
	}
}
