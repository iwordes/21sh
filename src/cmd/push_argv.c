/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 21:17:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 16:06:31 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Append arguments to the argv of a command.
*/

void	cmd_push_argv(t_cmd *cmd, char **argv)
{
	long	argc;
	long	i;

	i = cmd->argc;
	argc = 0;
	while (argv[argc] != NULL)
		argc += 1;
	cmd_grow(cmd, cmd->argc += argc);
	while (i < cmd->argc)
		cmd->argv[i++] = *(argv++);
}
