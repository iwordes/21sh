/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 10:48:13 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 14:58:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

pid_t	sh_meta_exec(t_exe *exe)
{
	char	*bin;
	pid_t	pid;

	if (!(bin = sh_meta_path(exe->argv[0])))
		return (-1);
	if ((pid = fork()) != 0)
		return (pid);
	dup2(exe->fd[0], 0);
	dup2(exe->fd[1], 1);
	dup2(exe->fd[2], 2);
	errno = 0;
	if (execve(bin, exe->argv, g_mn.env))
		exit(-1);
	return (-1);
}
