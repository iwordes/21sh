/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:27:14 by iwordes           #+#    #+#             */
/*   Updated: 2017/06/22 09:57:31 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define TK ps->tk[*t]
#define EXE ps->exe[ps->exe_len]
#define O_PERM_1 (TK.type <= TKT_R_O2) ? (O_WRONLY | O_CREAT) : (O_RDONLY)
#define O_PERM (O_PERM_1 | ((TK.type == TKT_R_O2) ? (O_APPEND) : (0)))

/*
** TODO: Fix redirs: Delay file opening til later stage
*/

static bool	rhs_(t_ps *ps, uint32_t *t, uint32_t i)
{
	char	*file;
	int		p[2];

	file = (TK.str[i] != 0) ? (TK.str + i) : (ps->tk[*t + 1].str);
	if (TK.type != TKT_R_I2 && *file != '&')
		ps->file = file;
	else if (TK.type != TKT_R_I2)
	{
		ps->rhs = ft_atoi(file + 1);
		if (file[1] == '-' && file[2] == 0)
			ps->rhs = -2;
	}
	else
	{
		if (pipe(p))
			PSFAIL("Could not create pipe for heredoc.");
		write(p[1], file, ft_strlen(file));
		close(p[1]);
		ps->rhs = p[0];
	}
	return (true);
}

#define BAD_RD_TYPE(T) (T != 0 && T != 1)

static bool	post_(t_ps *ps)
{
	if (ps->lhs < 0)
		ps->lhs = 1;
	if (ps->lhs > 0 && ps->rhs == 0)
		ps->rhs = (ps->lhs > 1) + 1;
	else if (ps->lhs > 2)
		PSFAIL("File descriptor too large.");
	if (EXE.fd[ps->lhs] > 2)
		close(EXE.fd[ps->lhs]);
	if (!ps->file)
		EXE.fd[ps->lhs] = ps->rhs;
	else
		EXE.file[ps->lhs] = ps->file;
	return (true);
}

bool		ps_proc_redir(t_ps *ps, uint32_t *t)
{
	uint32_t	i;

	i = 0;
	ps->lhs = -1;
	ps->rhs = -1;
	ps->file = NULL;
	if (*t + 1 >= ps->tk_len || BAD_RD_TYPE(ps->tk[*t + 1].type))
		PSFAIL("Redirection to nowhere.");
	if (ft_isdigit(TK.str[0]))
		ps->lhs = ft_atoi(TK.str);
	ITER(i, ft_isdigit(TK.str[i]));
	if (TK.str[i] == '<')
		ps->lhs = 0;
	ITER(i, TK.str[i] == '<' || TK.str[i] == '>');


	if (!rhs_(ps, t, i))
		return (false);
	if (!post_(ps))
		return (false);


	*t += (TK.str[i] == 0);
	*t += 1;
	return (true);
}
