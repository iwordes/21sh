/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 11:20:38 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 14:26:30 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Increase the available space for arguments in a cmd.
*/

void	cmd_grow(t_cmd *cmd, size_t c)
{
	char	**tmp;

	if (c < cmd->l)
		return ;
	MGUARD(tmp = MALT(char*, cmd->l * 2));
	ft_memcpy(tmp, cmd->argv, sizeof(char*) * cmd->l);
	ft_bzero(tmp + cmd->l, sizeof(char*) * cmd->l);
	free(cmd->argv);
	cmd->argv = tmp;
	cmd->l *= 2;
}
