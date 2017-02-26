/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:23:14 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 13:37:58 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	cmd_push_redir(t_cmd *cmd, int from, int over)
{
	t_redir	*head;
	t_redir	*rd;

	MGUARD(rd = redir_new());
	rd->from = from;
	rd->over = over;
	head = cmd->redir;
	if (head == NULL)
		cmd->redir = rd;
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = rd;
	}
}
