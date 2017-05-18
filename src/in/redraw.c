/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:16:04 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/18 13:36:35 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define LEN(S) ft_strlen(S)
#define LN in->ln[y]

#define MIN_1 (MIN(len - i, W))
#define MIN_2 (MIN(n - i, W - (x % W)))

static void	draw(const char *ps, const char *ln, size_t n, bool newln)
{
	static size_t	x;
	size_t			len;
	size_t			i;
	uint32_t		tmp;

	if (ps)
		x = 0;
	else
		ps = "";
	i = 0;
	len = LEN(ps);
	while (i < len)
	{
		tmp = MIN_1;
		(i) && write(1, "\n", 1);
		write(1, ps + i, tmp);
		x += tmp;
		i += tmp;
	}
	i = 0;
	while (i < n)
	{
		tmp = MIN_2;
		write(1, ln + i, tmp);
		(tmp == W - (x % W)) && write(1, "\n", 1);
		x += tmp;
		i += tmp;
	}
	if (newln)
		write(1, "\n", 1);
}

#define LONGEST (LN.ln + in->x + in->s)

static void	drawln(t_in *in, uint32_t y)
{
	if (in->s < 0)
	{
		draw(LN.ps, LN.ln, in->x + in->s, 0);
		write(1, "\e[7m", 4);
		draw(NULL, LONGEST, -in->s, 0);
		write(1, "\e[0m" "\e[s", 7);
		draw(NULL, LN.ln + in->x, LEN(LN.ln + in->x), 1);
	}
	else
	{
		draw(LN.ps, LN.ln, in->x, 0);
		write(1, "\e[s" "\e[7m", 7);
		draw(NULL, LN.ln + in->x, in->s, 0);
		write(1, "\e[0m", 4);
		draw(NULL, LONGEST, LEN(LONGEST), 1);
	}
}

void		in_redraw(t_in *in)
{
	uint32_t	i;
	uint32_t	y;

	i = 0;
	y = 0;
	g_mn.in = NULL;
	tm_goto(-g_mn.x, -g_mn.y);
	write(1, "\e[J", 3);
	while (y < in->len)
	{
		if (y != in->y)
			draw(LN.ps, LN.ln, LEN(LN.ln), true);
		else
		{
			drawln(in, y);
			g_mn.x = (LN.ps_len + in->x) % W;
			g_mn.y = (LN.ps_len + in->x + i) / W;
		}
		i += LN.len + LN.ps_len;
		i += W - (i % W);
		y += 1;
	}
	write(1, "\e[u", 3);
	g_mn.in = in;
}
