/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 14:07:48 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/25 11:39:11 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	cmds_grow(t_cmds *cmds, size_t c)
{
	t_cmd	*tmp;

	if (c < cmds->l)
		return ;
	MGUARD(tmp = MALT(t_cmd, (cmds->l * 2) + 1));
	ft_memcpy(tmp, cmds->cmd, sizeof(t_cmd) * cmds->l);
	ft_bzero(tmp + cmds->l, sizeof(t_cmd) * (cmds->l + 1));
	free(cmds->cmd);
	cmds->cmd = tmp;
	cmds->l *= 2;
}
