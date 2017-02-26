/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:31:13 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 11:56:46 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Placeholder command-executor.
*/

void	shell(void)
{
	char	*in;
	t_token	*tk;
	t_cmds	cmds;

	cmds_init(&cmds);
	while (ft_printf("$ ") && (in = input()) != NULL)
	{
		ft_printf("Processing command...\n");
		ft_printf("\"%s\"\n", in);
		tk = lex(in);
		ft_printf("after lex\n");
		debug_tokens(tk);
		if (!parse(&cmds, tk))
			continue ;
		ft_printf("after parse\n");
		exec_cmds(&cmds);
		ft_printf("after exec\n");
		tk_del(tk);
		free(in);
	}
	ft_putstr("exit\n");
	free(in);
}
