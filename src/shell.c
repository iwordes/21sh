/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:31:13 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/18 15:08:13 by iwordes          ###   ########.fr       */
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

	while ((in = input()) != NULL)
	{
		cmds_init(&cmds);

		ft_printf("Processing command... (\"%s\")\n", in);

		tk = lex(in);

		//ft_printf("+ lex\n");
		//debug_tokens(tk);

		if (tk->type != 255 && parse(&cmds, tk))
		{
			//ft_printf("+ parse\n");
			//debug_cmds(&cmds);

			exec_cmds(&cmds);
		}

		cmds_del(&cmds);
		tk_del(tk);
		free(in);
	}
	ft_putstr("exit\n");
	free(in);
}
