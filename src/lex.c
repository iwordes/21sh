/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:51:10 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 11:43:07 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static bool	(*g_patt[])(const char*) =
{
	patt_pipe,
	patt_redir,
	patt_sep,
	patt_str1_2,
	NULL
};

static void	(*g_lx[])(t_token*, const char**, bool*) =
{
	lx_pipe,
	lx_redir,
	lx_sep,
	lx_str1_2,
	lx_str
};

static t_token	*panic_(t_token *tk)
{
	t_token	*tmp;

	while (tk != NULL)
	{
		tmp = tk->next;
		free(tk->val);
		free(tk);
		tk = tmp;
	}
	return (NULL);
}

t_token		*lex(const char *ln)
{
	t_token	*head;
	t_token	*tk;
	bool	err;
	size_t	p;

	err = false;
	MGUARD(head = tk_new());
	tk = head;
	while (*ln != 0)
	{
		p = 0;
		ITER(p, g_patt[p] != NULL && !g_patt[p](ln));
		g_lx[p](tk, &ln, &err);
		if (err)
			return (panic_(head));
		MGUARD(tk->next = tk_new());
		tk = tk->next;
		tk->adj = !(ft_isspace(*ln));
		while (ft_isspace(*ln))
			ln += 1;
	}
	return (head);
}
