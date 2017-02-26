/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 13:52:54 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/25 13:03:08 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Enact a list of queued dup2 calls.
*/

void	redir(t_redir *rd)
{
	while (rd != NULL)
	{
		if (rd->path != NULL)
			rd->from = open(rd->path, rd->opt);
		else if (rd->doc != NULL)
			rd->from = heredoc(rd->doc);
		if (rd->from >= 0 && rd->over >= 0)
			dup2(rd->from, rd->over);
		else if (rd->from >= 0 && rd->over < 0)
			close(rd->from);
		rd = rd->next;
	}
}
