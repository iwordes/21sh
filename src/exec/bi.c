/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:20:37 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/22 15:44:45 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static char		*g_bicmd[] =
{
	"exit",
	NULL
};

static int		(*g_bi[])(char**) =
{
	bi_exit
};

bool		is_bi(const char *str)
{
	size_t	i;

	i = ~0L;
	while (g_bicmd[i += 1] != NULL)
		if (ft_striequ(g_bicmd[i], str))
			return (true);
	return (false);
}

#define IS_RESV(D) (D == std[0] || D == std[1] || D == std[2])

static void	redir_(t_redir *rd, int std[3])
{
	int		fd;

	while (rd != NULL)
	{
		if (!IS_RESV(rd->over))
		{
			if (rd->path != NULL)
				rd->from = open(rd->path, rd->opt);
			else if (rd->doc != NULL)
				rd->from = heredoc(rd->doc);
			if (rd->from >= 0 && rd->to >= 0)
				dup2(rd->from, rd->over);
			else if (rd->from >= 0 && rd->over < 0)
				close(rd->from);
		}
		rd = rd->next;
	}
}

static void	unredir_(t_redir *rd, int std[3])
{
	while (rd != NULL)
	{
		if (rd->from >= 0 && !IS_RESV(rd->from))
			close(rd->from);
		if (rd->over >= 0 && !IS_RESV(rd->over))
			close(rd->over);
		rd = rd->next;
	}
}

/*
** Don't run either of these before checking is_bi() first.
*/

int			exec_bi(t_cmd *cmd)
{
	int		std[3];
	int		state;
	size_t	i;

	i = ~0L;
	while (g_bicmd[i += 1] != NULL)
		if (ft_stricmp(g_bicmd[i], cmd->argv[0]))
			break ;
	std[0] = dup(0);
	std[1] = dup(1);
	std[2] = dup(2);
	redir_(cmd->redir);
	state = g_bi[i](cmd->argv);
	unredir_(cmd->redir);
	dup2(std[0], 0);
	dup2(std[1], 1);
	dup2(std[2], 2);
	close(std[0]);
	close(std[1]);
	close(std[2]);
	return (state);
}

pid_t		exec_bi_async(t_cmd *cmd)
{
	pid_t	pid;
	size_t	i;

	if ((pid = fork()) != 0)
		return (pid);
	i = 0;
	while (g_bicmd[i] != NULL)
		if (ft_striequ(g_bicmd[i], cmd->argv[0]))
			break ;
	redir(cmd->redir);
	exit(g_bi[i](cmd->argv));
	return (0);
}
