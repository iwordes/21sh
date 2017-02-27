/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 21:17:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 15:53:41 by iwordes          ###   ########.fr       */
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

	ft_printf("\e[96m>> Validate: argv:\n");
	for (int k = 0; k < argc; k += 1)
		ft_printf("\"%s\", ", argv[k]);
	ft_printf("\e[0m\n");

	ft_printf("After lenloop\n");
	cmd_grow(cmd, cmd->argc += argc);
	ft_printf("After cmd_grow\n");
	ft_printf("cmd->argc: %d (new: %d)\n", i, cmd->argc);
	while (i < cmd->argc)
		cmd->argv[i++] = *(argv++);
	ft_printf("After copyloop\n");

	ft_printf("\e[91m>> Validate: cmd->argv, post-append\n");
	for (int u = 0; u < cmd->argc; u += 1)
		ft_printf("\"%s\", ", cmd->argv[u]);
	ft_printf("\e[0m\n");
}
