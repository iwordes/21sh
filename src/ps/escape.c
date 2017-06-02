/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:36:55 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/31 15:28:57 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define TK ps->tk[t]

bool	ps_escape(t_ps *ps)
{
	uint32_t	i;
	uint32_t	t;

	t = 0;
	while (t < ps->tk_len)
	{
		i = 0;
		if (TK.type != TKT_QUOT)
			while (TK.str[i] != 0)
			{
				if (TK.str[i] == '\\')
				{
					if (TK.str[i + 1] == 0)
						PSFAIL("Backslash at EOL.");
					ft_strcut(TK.str, i, 1);
				}
				i += 1;
			}
		t += 1;
		ITER(t, TK.flag & TKF_ADJ);
	}
	return (true);
}
