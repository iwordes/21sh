/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:15:28 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/10 13:14:03 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

/*
** TODO: Line Insertion
*/

#define LN in->ln[in->y]
#define IS_QUOTE(C) (C == '\"' || C == '\'' || C == '\\')

static bool	test_parse(t_in *in)
{
	char	q;
	size_t	x;
	size_t	y;

	q = 0;
	y = 0;
	while (y < in->len)
	{
		x = 0;
		while (x < LN.len)
		{
			if (q == '\\')
				q = 0;
			else if (LN.ln[x] == q)
				q = 0;
			else if (IS_QUOTE(LN.ln[x]))
				q = LN.ln[x];
			x += 1;
		}
		y += 1;
	}
	return (q == 0);
}

void		in_submit(t_in *in)
{
	if (test_parse(in))
		in->submit = true;
	else if (in->y + 1 == in->len)
	{
		if (in->len == in->mem)
		{
			MGUARD(DRALT(in->ln, t_inline, in->mem * 2, in->mem));
			in->mem *= 2;
		}
		in->len += 1;
		in->y += 1;
		in->x = 0;
		in_redraw(in);
	}
}
