/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 11:27:13 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/10 11:30:32 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	sel_del(t_in *in)
{
	if (in->s != 0)
	{
		if (in->s > 0)
		{
			ft_strcut(LN.ln, in->x, in->s);
			LN.len -= in->s;
		}
		else
		{
			ft_strcut(LN.ln, in->x + in->s, -in->s);
			LN.len += in->s;
			in->x += in->s;
		}
	}
}
