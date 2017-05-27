/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 10:48:13 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 14:54:48 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

pid_t	sh_meta_exec(t_exe *exe)
{
	char	*bin;
	pid_t	pid;

	ft_putstr("\e[95msh_meta_exec\e[0m\n");

	if (!(bin = sh_meta_path(exe->argv[0])))
	{
		ft_putstr("\e[91msh_meta_exec\e[0m\n");
		return (-1);
	}

	ft_printf("\e[93m\"%s\"\e[0m\n", bin);

	if ((pid = fork()) != 0)
	{
		ft_putstr("\e[92msh_meta_exec\e[0m\n");
		return (pid);
	}
	dup2(exe->fd[0], 0);
	dup2(exe->fd[1], 1);
	dup2(exe->fd[2], 2);
	errno = 0;
	if (execve(bin, exe->argv, g_mn.env))
	{
		perror("\e[91mexecve\e[0m");
		exit(-1);
	}
	return (-1);
}
