/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 13:45:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/18 13:58:45 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define TK ps->tk[i]

bool	ps_home(t_ps *ps)
{
	uint32_t	i;

	i = 0;
	while (i < ps->tk_len)
	{
		if (TK.type == TKT_NONE && TK.str[0] == '~')
		{
			TK.str[0] = '#';
			;
			if (0)
			{
				// TODO: Grow string
				// ...
				if (TK.str == NULL)
					return (false);
			}
			// ft_strcut(TK.str, 0, 1);
			// ft_strins(TK.str, 0, env_gets("HOME"));
		}
		i += 1;
		while (i < ps->tk_len && (TK.flag & TKF_ADJ))
			i += 1;
	}
	return (true);
}
