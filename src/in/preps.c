/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 14:36:56 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/25 14:38:53 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

bool	in_preps(t_in *in)
{
	char	q;
	size_t	x;
	size_t	y;

	q = 0;
	y = ~0;
	while (++y < in->len)
	{
		x = ~0;
		if (q == '\\')
			q = 0;
		while (++x < LN.len)
		{
			if (q == '\\')
				q = 0;
			else if (LN.ln[x] == q)
				q = 0;
			else if (q == 0 && IS_QUOTE(LN.ln[x]))
				q = LN.ln[x];
			else if (ft_strncmp(LN.ln + x, "<<", 2))
				;
		}
	}
	return (q == 0);
}
