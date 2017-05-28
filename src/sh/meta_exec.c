/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 10:48:13 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/28 15:01:55 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define FD exe->fd

bool	sh_meta_exec(t_exe *exe)
{
	char	*bin;

	if (!(bin = sh_meta_path(exe->argv[0])))
		return (false);
	if ((exe->pid = fork()))
		return (exe->pid > 0);
	dup2(FD[0], 0);
	dup2(FD[1], 1);
	dup2(FD[2], 2);
	fd_close(FD[0]);
	fd_close(FD[1]);
	fd_close(FD[2]);
	if (execve(bin, exe->argv, g_mn.env))
		exit(-1);
	return (true);
}
