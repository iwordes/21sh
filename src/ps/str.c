/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 14:26:14 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 14:29:13 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Failure to allocate space for arguments is not a critical failure.
*/

void	ps_str(t_cmd *cmd, t_token *tk)
{
	char	**argv;
	char	*tmp;

	//if ((argv = subs_var(tk)) == NULL)
	//	PS_ERR("malloc failure");
	MGUARD(argv = subs_var(tk));
	if (!tk->adj)
		cmd_push_argv(cmd, argv);
	else
	{
		MGUARD(tmp = ft_strjoin(cmd->argv[cmd->argc - 1], argv[0]));
		free(cmd->argv[cmd->argc - 1]);
		cmd->argv[cmd->argc - 1] = tmp;
		cmd_push_argv(cmd, argv + 1);
	}
}
