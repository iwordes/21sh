/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 12:35:42 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 13:24:37 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

#define BOOLS(COND) ((COND) ? "true" : "false")

void	debug_cmds(t_cmds *cmds)
{
	t_cmd	*cmd;
	size_t	i;
	int		a;

	ft_printf("\e[96mCommands:\e[0m\n");
	i = 0;
	while (i < cmds->l)
	{
		cmd = cmds->cmd + i;
		ft_printf("{\n");
		ft_printf("    \"argc\": %d\n", cmd->argc);
		ft_printf("    \"argv\": [\n");
		a = 0;
		while (a < cmd->argc)
		{
			ft_printf("        \"%s\"%s\n", cmd->argv[a],
				(a + 1 < cmd->argc) ? "," : "");
			a += 1;
		}
		ft_printf("    ]\n" "    \"l\": %zu\n", cmd->l);
		ft_printf("    \"pipe\": %s\n", BOOLS(cmd->pipe));
		ft_printf("}\n");
		i += 1;
	}
}
