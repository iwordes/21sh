/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:55:31 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/22 16:24:06 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		exec_cmd(t_cmd *cmd)
{
	if (ft_strchr(cmd->argv[0], '/'))
		return (exec_path(cmd, cmd->argv[0]));
	else if (is_bi(cmd->argv[0]))
		return (exec_bi(cmd));
	else
		return (exec_name(cmd));
}

pid_t	exec_cmd_async(t_cmd *cmd)
{
	if (ft_strchr(cmd->argv[0], '/'))
		return (exec_path_async(cmd, cmd->argv[0]));
	else if (is_bi(cmd->argv[0]))
		return (exec_bi_async(cmd));
	else
		return (exec_name_async(cmd));
}
