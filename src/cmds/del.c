/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 13:44:20 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 13:53:58 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static void	redir_del(t_redir *rd)
{
	t_redir	*tmp;

	while (rd != NULL)
	{
		tmp = rd->next;
		free(rd->path);
		free(rd->doc);
		free(rd);
		rd = tmp;
	}
}

void	cmds_del(t_cmds *cmds)
{
	size_t	i;
	int		a;

	i = 0;
	while (i < cmds->l)
	{
		a = 0;
		while (a < cmds->cmd[i].argc)
			free(cmds->cmd[i].argv[a++]);
		free(cmds->cmd[i].argv);
		redir_del(cmds->cmd[i].redir);
		i += 1;
	}
	free(cmds->cmd);
}
