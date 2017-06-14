/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:15:28 by iwordes           #+#    #+#             */
/*   Updated: 2017/06/13 19:13:41 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

/*
** TODO: Line Insertion
*/

#define LN in->ln[*y]
#define CMP (ft_strncmp(eof, LN.ln, l) == 0)

static bool	pps_ri2(t_in *in, size_t *x, size_t *y)
{
	char	*eof;
	size_t	l;
	size_t	n;

	n = 0;
	*x += 2;
	ITER(*x, *x < LN.len && ft_isspace(LN.ln[*x]));
	if (*x == LN.len)
		return (false);
	eof = LN.ln + *x;
	l = ft_struntil(eof, '\n');
	*x = 0;
	*y += 1;
	while (*y < in->len && !CMP)
		*y += 1;
	return (*y < in->len);
}

#undef LN
#define LN in->ln[y]
#define IS_QUOTE(C) (C == '\"' || C == '\'' || C == '\\')

static bool	pps_logic(t_in *in, size_t *y, char *q)
{
	size_t	x;

	x = ~0;
	if (*q == '\\')
		*q = 0;
	while (++x < in->ln[*y].len)
	{
		if (*q == '\\')
			*q = 0;
		else if (in->ln[*y].ln[x] == *q)
			*q = 0;
		else if (*q == 0 && IS_QUOTE(in->ln[*y].ln[x]))
			*q = in->ln[*y].ln[x];
		else if (ft_strnequ(in->ln[*y].ln + x, "<<", 2))
		{
			if (!pps_ri2(in, &x, y))
				return (false);
			break ;
		}
	}
	return (true);
}

static bool	preparse(t_in *in)
{
	char	q;
	size_t	y;

	q = 0;
	y = ~0;
	while (++y < in->len)
		if (!pps_logic(in, &y, &q))
			return (false);
	return (q == 0);
}

#undef LN
#define LN in->ln[in->y]

void		in_submit(t_in *in)
{
	if (preparse(in))
		in->submit = true;
	else if (in->y + 1 == in->len)
	{
		in->len += 1;
		if (in->len >= in->mem)
		{
			MGUARD(DRALT(in->ln, t_inline, in->mem * 2, in->mem));
			ft_bzero(in->ln + in->mem, in->mem * sizeof(t_inline));
			in->mem *= 2;
		}
		in->y += 1;
		in->x = 0;
		LN.ps = env_gets("PS2");
		LN.ps_len = ft_strlen(LN.ps);
		MGUARD(LN.ln = ZALT(char, 128));
		LN.mem = 128;
		in_redraw(in);
	}
}
