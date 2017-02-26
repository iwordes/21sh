/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:23:44 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/25 11:42:11 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	ps_heredoc(t_cmd *cmd, t_token *tk, int over)
{
	int		pip[2];

	if (over == -1)
		over = 0;
	pipe(pip);
	write(pip[1], tk->val, ft_strlen(tk->val));
	close(pip[1]);
	cmd_push_redir(cmd, pip[0], over);
}
