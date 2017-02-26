/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 19:19:17 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/23 21:12:12 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Iterating ASCII to Unsigned
*/
#define IATOU(V,I,E) while (ISDIG(E)) { V = (V * 10) + (E - '0'); I += 1; }

#define ERR_(M)

static void		lhs_(t_redir *r, const char **str, bool *err)
{
	if (ft_isdigit(**str))
	{
		r->from = 0;
		while (ft_isdigit(**str))
		{
			r->from = (r->from * 10) + (**str - '0');
			*str += 1;
		}
	}
	(void)err;
}

static void		sym_(t_redir *r, const char **str, bool *err)
{
	if ((*str)[0] == '>' && (*str)[1] == '>')
		r->type = RD_AOUT;
	else if ((*str)[0] == '>' && (*str)[1] != '<')
		r->type = RD_OUT;
	else if ((*str)[0] == '<' && (*str)[1] == '<')
		r->type = RD_DOC;
	else if ((*str)[0] == '<' && (*str)[1] != '>')
		r->type = RD_IN;
	else
		LX_ERR("Invalid redirection operator");
	*str += 1 + ((*str)[1] == '<' || (*str)[1] == '>');
	if (r->type == RD_IN || r->type == RD_DOC)
	{
		r->over = r->from;
		r->from = -1;
	}
}

/*
** If no
*/

static void		rhs_(t_redir *r, const char **str, bool *err)
{
	int		tmp;

	if (**str == '&' && (*str += 1))
	{
		if (**str == '-')
			return ;
		tmp = 0;
		if (!ft_isdigit(**str))
			LX_ERR("Invalid file descriptor.");
		IATOU(tmp, *str, **str);
		if (r->type == RD_IN || r->type == RD_DOC)
			r->from = tmp;
		else
			r->over = tmp;
	}
}

static void		rhs_doc_(t_redir *r, const char **str, bool *err)
{
	char	*eof;
	size_t	dl;
	size_t	tl;

	dl = 0;
	tl = 0;
	ITER(*str, ft_isspace(**str));
	eof = (char*)*str;
	ITER(tl, eof[tl] != 0 && !ft_isspace(eof[tl]));
	if (tl == 0)
		LX_ERR("heredoc: No EOF token given!");
	*str += tl;
	ITER(*str, ft_isspace(**str) && **str != '\n');
	*str += (**str == '\n');
	ITER(dl, (*str)[dl] != 0 && !ft_strnequ(eof, *str + dl, tl));
	if ((*str)[dl] == 0)
		LX_ERR("heredoc: No matching end token!");
	while ((*str)[dl] != '\n' && ft_isspace((*str)[dl -= 1]))
		;
	dl -= ((*str)[dl] == '\n');
	if ((r->doc = ft_strsub(*str, 0, dl)) == NULL)
		LX_ERR("Failed to allocate enough space for heredoc!");
}

#define ERRCHK_(O) O; if (*err) { free(r); return; }

void			lx_redir(t_token *tk, const char **str, bool *err)
{
	t_redir	*r;

	MGUARD(r = redir_new());
	ERRCHK_(lhs_(r, str, err));
	ERRCHK_(sym_(r, str, err));
	if (r->type == RD_DOC)
		rhs_doc_(r, str, err);
	else
		rhs_(r, str, err);
	ERRCHK_();
	tk->type = TK_REDIR;
	tk->val = (char*)r;
}
