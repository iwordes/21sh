/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 20:27:13 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/25 12:12:27 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static int	choose_o(int redir)
{
	if (redir == RD_IN)
		return (O_RDONLY);
	if (redir == RD_OUT)
		return (O_WRONLY);
	if (redir == RD_AOUT)
		return (O_WRONLY | O_APPEND);
	return (0);
}

static int	ps_atoi_(const char **str)
{
	int		val;

	val = 0;
	while (ft_isdigit(**str))
		val += *((*str)++) - '0';
	return (val);
}

/*
** RHS:
** &([0-9]+): Redirect to descriptor
** (LABEL) (.*) $1: (Special) heredoc literal
** ([^ \t\n\f\v]+): Redirect from/to file
*/

static void	patt_redir_(const char *str, int *redir, int *lhs, int *rhs)
{
	if (ft_isdigit(*str))
		*lhs = ps_atoi_(&str);
	if (*str == '<' && *(str + 1) == '<')
		(*redir = RD_DOC) && (str += 1);
	else if (*str == '<')
		*redir = RD_IN;
	else if (*str == '>' && *(str + 1) == '>')
		(*redir = RD_AOUT) && (str += 1);
	else if (*str == '>')
		*redir = RD_OUT;
	else
		PS_ERR("Invalid redirection.");
	str += 1;
	if (ft_isdigit(*str))
		rhs = ps_atoi_(&str);
	else if (redir != RD_DOC)
	{
		if ((rhs = open(str, choose_o(*redir))) == -1)
			PS_ERR("Failed to open \"%s\" for redirection.");
	}
}

void	ps_redir(t_cmd *cmd, t_token *tk)
{
	int		redir;
	int		lhs;
	int		rhs;

	src = -1;
	dest = -1;
	patt_redir_(tk->val, &redir, &dest, &src);
	if (redir == RD_DOC)
		ps_heredoc(cmd, tk, src)
	else
	{
		if (lhs == -1)
			lhs = (redir == RD_IN) ? 0 : 1;
		if (redir == RD_IN)
			cmd_push_redir(cmd, rhs, lhs);
		else
			cmd_push_redir(cmd, lhs, rhs);
	}
}
