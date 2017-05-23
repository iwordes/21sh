/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:27:14 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/22 15:48:35 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define TK ps->tk[*t]
#define EXE ps->exe[ps->exe_len]
#define O_PERM_1 (TK.type <= TKT_R_O2) ? (O_WRONLY | O_CREAT) : (O_RDONLY)
#define O_PERM (O_PERM_1 | ((TK.type == TKT_R_O2) ? (O_APPEND) : (0)))

static bool	rhs_(t_ps *ps, uint32_t *t, int *rhs, uint32_t i)
{
	char	*file;
	int		p[2];

	file = (TK.str[i] != 0) ? (TK.str + i) : (ps->tk[*t + 1].str);
	if (TK.type != TKT_R_I2)
	{
		if (*file != '&')
		{
			if ((*rhs = open(file, O_PERM, 0600)) < 0)
				PSFAIL("Could not open file for redirection.");
		}
		else
		{
			*rhs = ft_atoi(file);
			if (file[1] == '-' && file[2] == 0)
				*rhs = -1;
		}
	}
	else
	{
		if (pipe(p))
			PSFAIL("Could not create pipe for heredoc.");
		write(p[1], file, ft_strlen(file));
		close(p[1]);
		*rhs = p[0];
	}
	return (true);
}

bool	ps_proc_redir(t_ps *ps, uint32_t *t)
{
	char		*file;
	int			lhs;
	int			rhs;
	uint32_t	i;

	i = 0;
	lhs = -1;
	rhs = -1;
	file = NULL;
	if (ft_isdigit(TK.str[0]))
		lhs = ft_atoi(TK.str);
	ITER(i, ft_isdigit(TK.str[i]));
	ITER(i, TK.str[i] == '<' || TK.str[i] == '>');
	rhs_(ps, t, &rhs, i);
	if (lhs < 2 || (lhs == 2 && !(TK.type <= TKT_R_O2)))
		lhs = (TK.type <= TKT_R_O2);
	else if (lhs > 2)
		PSFAIL("File descriptor too large.");
	if (EXE.fd[lhs] > 2)
		close(EXE.fd[lhs]);
	EXE.fd[lhs] = rhs;
	*t += (TK.str[i] == 0);
	*t += 1;
	return (true);
}
