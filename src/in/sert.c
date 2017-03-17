/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sert.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:18:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/17 13:01:56 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Insert a keypress of text into the input buffer.
** If necessary, allocate more space for the current line.
** Finally, reprint the input buffer.
*/

#define LN (in->ln[in->y])

void	in_sert(t_in *in, char buff[2])
{
	char	*tmp;

	buff[1] = 0;
	if (LN.ln_len + 1 >= LN.mem)
	{
		MGUARD(tmp = (char*)malloc(LN.mem * 2));
		ft_memcpy(tmp, LN.ln, LN.mem);
		free(LN.ln);
		LN.ln = tmp;
		LN.mem *= 2;
	}
	LN.ln_len += 1;
	ft_strins(LN.ln, buff, in->x);

	sh_right();
	in->x += 1;
	in_print(in);
}
