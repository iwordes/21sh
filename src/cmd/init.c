/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 14:09:24 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 15:51:33 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

#define N_ARGS 8

void	cmd_init(t_cmd *cmd)
{
	MGUARD(cmd->argv = ZALT(char*, N_ARGS));
	cmd->l = N_ARGS;
	cmd->argc = 0;
	cmd->pipe = false;
	cmd->redir = NULL;
}
