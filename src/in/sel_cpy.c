/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 10:01:00 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/18 10:24:14 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

bool	in_sel_cpy(t_in *in)
{
	free(in->buff);
	in->buff = ft_strsub(LN.ln, in->x, in->sel);
	in->sel = 0;
	in_print(in);
	return (false);
}
