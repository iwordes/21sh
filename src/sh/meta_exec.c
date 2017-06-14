/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 10:48:13 by iwordes           #+#    #+#             */
/*   Updated: 2017/06/13 18:51:20 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define EXE ps->exe[i]

static void	filedes_(t_ps *ps, uint32_t i)
{
	dup2(EXE.fd[0], 0);
	dup2(EXE.fd[1], 1);
	dup2(EXE.fd[2], 2);
	i = ~0;
	while (++i < ps->exe_len)
	{
		fd_close(EXE.fd[0]);
		fd_close(EXE.fd[1]);
		fd_close(EXE.fd[2]);
	}
}

bool		sh_meta_exec(t_ps *ps, uint32_t i)
{
	char	*bin;

	if (!(bin = sh_meta_path(EXE.argv[0])))
		return (false);
	if ((EXE.pid = fork()))
		return (EXE.pid > 0);
	filedes_(ps, i);
	if (execve(bin, EXE.argv, g_mn.env))
		exit(-1);
	return (true);
}
