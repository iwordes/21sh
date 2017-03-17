/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wd_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:03:45 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/17 13:23:50 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

#define LN in->ln[in->y]

bool	in_wd_left(t_in *in)
{
	in_left(in);
	while (in->x > 0 && !ft_isspace(LN.ln[in->x]))
		in_left(in);
	while (in->x > 0 && ft_isspace(LN.ln[in->x - 1]))
		in_left(in);
	return (false);
}
