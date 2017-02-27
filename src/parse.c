/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 20:56:56 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 16:04:56 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** By the end of parse(), guarantee that no syntax errors exist.
*/

#undef PS_ERR
#define PS_ERR(M) { ps_err(M); return (false); }

bool	parse(t_cmds *cmds, t_token *tk)
{
	size_t	c;

	c = 0;
	cmd_init(cmds->cmd);
	while (tk != NULL)
	{
		cmds_grow(cmds, c);
		if (TK_ISSTR(tk))
			ps_str(cmds->cmd + c, tk);
		else if (TK_ISPIPE(tk) || TK_ISSEP(tk))
		{
			if (TK_ISPIPE(tk) && (tk->next == NULL || !TK_ISSTR(tk->next)))
				PS_ERR("No command to pipe into.");
			if (TK_ISPIPE(tk))
				cmds->cmd[c].pipe = true;
			c += 1;
			cmd_init(cmds->cmd + c);
		}
		tk = tk->next;
	}
	cmds->l = c + 1;
	return (true);
}
