/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 14:09:24 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/25 11:39:44 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

#define N_ARGS 8

void	cmd_init(t_cmd *cmd)
{
	int		i;

	i = 0;
	MGUARD(cmd->argv = MALT(char*, N_ARGS));
	ft_bzero(cmd->argv, sizeof(char*) * N_ARGS);
	cmd->l = N_ARGS;
	cmd->argc = 0;
	cmd->redir = ZALT(t_redir, 1);
	cmd->pipe = false;
}
