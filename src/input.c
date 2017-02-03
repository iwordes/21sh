/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:05:57 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/03 10:37:43 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static char	*g_patt[] =
{
	TM_UP,
	TM_DOWN,
	TM_RIGHT,
	TM_LEFT,
	"\b",
	"\x7f",
	NULL
};

static void	(*g_fn[])(char**, size_t*, size_t*) =
{
	in_up,
	in_down,
	in_right,
	in_left,
	in_bksp,
	in_bksp
};

static void	in_grow(char **cmd, size_t i, size_t *l)
{
	char	*new_cmd;

	if (i < *l)
		return ;
	while (*l <= i)
		*l *= 2;
	MGUARD(new_cmd = ft_strnew(*l));
	ft_strcpy(new_cmd, *cmd);
	free(*cmd);
	*cmd = new_cmd;
}

static int	in_proc(char **cmd, size_t *i, size_t *l)
{
	char	buff[8];
	int		r;
	int		p;

	while ((*((uint64_t*)buff) = 0) || (r = read(0, buff, 7)) != 0)
	{
		if (r == 0 && **cmd == 0)
			return (0);
		if (ft_strequ(buff, "\n") || ft_strequ(buff, "\r"))
			return (1);
		p = ~0;
		while (g_patt[p += 1] != NULL)
			if (ft_strequ(g_patt[p], buff))
			{
				g_fn[p](cmd, i, l);
				break ;
			}
		if (g_patt[p] != NULL)
			continue ;
		in_grow(cmd, *i + ft_strlen(buff), l);
		in_sert(cmd, i, l, buff);
	}
	return (r);
}

char		*input(void)
{
	char	*cmd;
	size_t	i;
	size_t	l;
	int		o;

	i = 0;
	l = 256;
	MGUARD(cmd = ft_strnew(l));
	if ((o = in_proc(&cmd, &i, &l)) < 0)
		exit(110);
	else if (o == 0)
	{
		free(cmd);
		return (NULL);
	}
	return (cmd);
}
