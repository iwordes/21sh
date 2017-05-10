/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:59:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/10 11:35:49 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	in_ctrl_c(t_in *in)
{
	if (in->s == 0)
		in->cancel = true;
	else
	{
		free(in->clip);
		if (in->s > 0)
			in->clip = ft_strsub(LN.ln + in->x, in->s);
		else
			in->clip = ft_strsub(LN.ln + in->x + in->s, -in->s);
	}
}
