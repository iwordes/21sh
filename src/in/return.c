/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 13:30:51 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/18 13:44:39 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

// What happens when the user presses enter in a middle line?
// What happens when the user presses enter in the middle of a line?

static void	grow_in_(t_in *in)
{
	t_inln	*tmp;

	if (in->l + 1 >= in->mem)
	{
		MGUARD(tmp = ZALT(t_inln, in->mem * 2));
		ft_memcpy(tmp, in->ln, sizeof(t_in) * in->mem);
		in->mem *= 2;
		free(in->ln);
		in->ln = tmp;
	}
}

#define CLN (in->ln[in->y])

static void	add_line_(t_in *in)
{
	grow_in_(in);
	in->x = 0;
	in->y += 1;
	in->l += 1;
	MGUARD(CLN.ps = ft_strdup(in->ps2));
	MGUARD(CLN.ln = ft_strnew(128));
	CLN.ps_len = in->ps2_len;
	CLN.mem = 128;
	in_print(in);
	in_goto(in, in->x, in->y);
}

#define LN (in->ln[y])
#define IS_Q(C) ((C) == '\\' || (C) == '\'' || (C) == '\"')

static bool	return_(t_in *in)
{
	size_t	x;
	size_t	y;
	char	q;

	q = 0;
	y = 0;
	while (y < in->l)
	{
		x = 0;
		while (x < LN.ln_len)
		{
			if (q == '\\')
				q = 0;
			else if (LN.ln[x] == q)
				q = 0;
			else if (IS_Q(LN.ln[x]))
				q = LN.ln[x];
			x += 1;
		}
		y += 1;
	}
	return (q == 0);
}

bool		in_return(t_in *in)
{
	if (return_(in))
		return (true);
	grow_in_(in);
	add_line_(in);
	return (false);
}
