/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sert.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:53:59 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/18 12:45:18 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define LN in->ln[in->y]

static void	clear(char *buff)
{
	uint8_t	i;

	i = 0;
	while (i < ft_strlen(buff))
	{
		if (buff[i] < 32 || buff[i] > 127)
			ft_strcut(buff, i, 1);
		else
			i += 1;
	}
}

void		in_sert(t_in *in, char *buff)
{
	uint8_t	len;

	clear(buff);
	len = ft_strlen(buff);
	in_hist_del(in);
	if (in->s != 0)
	{
		in_sel_del(in);
		in->s = 0;
	}
	if (in->x + len >= LN.mem)
	{
		MGUARD(DRALT(LN.ln, char, LN.mem * 2, LN.mem));
		LN.mem *= 2;
	}
	ft_strins(LN.ln, buff, in->x);
	LN.len += len;
	in->x += len;
	in_redraw(in);
}
