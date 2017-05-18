/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:16:04 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/18 13:12:47 by iwordes          ###   ########.fr       */
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

	// Issue: Maligned goto, misrepresented x/y
	tm_goto(-g_mn.x, -g_mn.y);
	write(1, "\e[J", 3);
	while (y < in->len)
	{
		if (y != in->y)
			draw(LN.ps, LN.ln, LEN(LN.ln), true);
		else
		{
			drawln(in, y);

			// It's saving the cursor at the wrong position!
			// Determined X/Y mismatch with new rendering system
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

/*

static void	in_redraw_cur(t_in *in, uint32_t y)
{
	if (in->s < 0)
	{
		write(1, LN.ln, in->x + in->s);
		write(1, "\e[7m", 4);
		write(1, LN.ln + in->x + in->s, -in->s);
		write(1, "\e[0m" "\e[s", 7);
		if (y + 1 < in->len)
			ft_putendl(LN.ln + in->x);
		else
			ft_putstr(LN.ln + in->x);
	}
	else
	{
		write(1, LN.ln, in->x);
		write(1, "\e[s" "\e[7m", 7);
		write(1, LN.ln + in->x, in->s);
		write(1, "\e[0m", 4);
		if (y + 1 < in->len)
			ft_putendl(LN.ln + in->x + in->s);
		else
			ft_putstr(LN.ln + in->x + in->s);
	}
}

void		in_redraw(t_in *in)
{
	uint32_t	i;
	uint32_t	y;

	i = 0;
	y = 0;
	tm_goto(-g_mn.x, -g_mn.y);
	write(1, "\e[J", 3);
	while (y < in->len)
	{
		i += LN.ps_len;
		ft_putstr(LN.ps);
		if (y != in->y)
			ft_putendl(LN.ln);
		else
		{
			in_redraw_cur(in, y);
			g_mn.x = (LN.ps_len + in->x) % g_mn.w;
			g_mn.y = (i + in->x) / g_mn.w;
		}
		i += LN.len;
		if (y + 1 < in->len)
			i += g_mn.w - (i % g_mn.w);
		y += 1;
	}
	write(1, "\e[u", 3);
}

*/
