/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:47:28 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 11:47:21 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** There will (should) never be an input where a cmd has pipe set and
** the subsequent cmd is NULL.
*/

void		exec_cmds(t_cmds *cmds)
{
	int		pip[2];
	size_t	d;
	size_t	i;

	i = 0;
	while (i < cmds->l)
	{
		d = i;
		while (cmds->cmd[i].pipe)
		{
			pipe(pip);
			cmd_push_redir(cmds->cmd + i, pip[1], 1);
			cmd_push_redir(cmds->cmd + i + 1, pip[0], 0);
			ft_printf("after push_redir\n");
			exec_cmd_async(cmds->cmd + i);
			i += 1;
		}
		exec_cmd(cmds->cmd + i);
		ft_printf("after exec_cmd\n");
		d = i - d;
		while (d--)
			waitpid(WAIT_ANY, NULL, 0);
		i += 1;
	}
}
