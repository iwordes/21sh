/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:36:38 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/11 13:31:44 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Reset the contents of a t_in and print a new prompt. (sim. Ctrl+C)
*/

void	in_reset(t_in *in)
{
	size_t	i;

	i = ~0L;
	in_eoi(in);
	while (in->ln[i += 1].ln != NULL)
	{
		in->ln[i].mem = 0;
		free(in->ln[i].ln);
		in->ln[i].ln = NULL;
		free(in->ln[i].ps);
		in->ln[i].ps = NULL;
		in->ln[i].ps_len = 0;
	}
	in->q = 0;
	in->x = 0;
	in->y = 0;
	MGUARD(in->ln[0].ps = ft_strdup(in->ps1));
	MGUARD(in->ln[0].ln = ft_strnew(256));
	in->ln[0].ps_len = in->ps1_len;
	in->ln[0].mem = 256;
	tm_nextln();
	ft_putstr(in->ln[0].ps);
}
