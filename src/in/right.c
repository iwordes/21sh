/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:22:07 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/08 12:25:14 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	in_right(t_in *in)
{
	if (in->x < in->ln_len)
	{
		in->x += 1;
		if ((in->ln[in->y].ps_len + in->x) % g_sh.cols == 1)
			tm_nextln();
		else
			tm_right();
	}
}