/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sert.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:18:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/13 17:22:33 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Insert a keypress of text into the input buffer.
** If necessary, allocate more space for the current line.
** Finally, reprint the input buffer.
*/

#define LN (in->ln[in->y])

bool	in_sert(t_in *in, char buff[8])
{
	char	*tmp;
	size_t	i;

	if (in->x + 1 > LN.m)
	{
		MGUARD(tmp = (char*)malloc(LN.m * 2));
		ft_memcpy(tmp, LN.ln, LN.m);
		free(LN.ln);
		LN.ln = tmp;
		LN.m *= 2;
	}
	ft_strins(LN.ln, buff, in->x);
	in_print(in);
	in->x += 1;
}
