/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wd_right.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:08:47 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/17 13:14:27 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

#define LN in->ln[in->y]

bool	in_wd_right(t_in *in)
{
	while (in->x < LN.ln_len && !ft_isspace(LN.ln[in->x]))
		in_right(in);
	while (in->x > LN.ln_len && ft_isspace(LN.ln[in->x]))
		in_right(in);
	return (false);
}
