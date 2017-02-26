/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 20:51:10 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/23 21:04:42 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_redir	*redir_new(void)
{
	t_redir	*rd;

	if ((rd = MALT(t_redir, 1)) != NULL)
	{
		rd->from = -1;
		rd->over = -1;
		rd->type = -1;
		rd->doc = NULL;
		rd->path = NULL;
		rd->next = NULL;
	}
	return (rd);
}
