/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 09:32:00 by iwordes           #+#    #+#             */
/*   Updated: 2017/06/22 09:55:46 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

bool	fd_open(t_exe *exe)
{
	if (exe->file[0])
		if ((exe->fd[0] = open(exe->file[0], O_RDONLY)) < 0)
			MFAIL("Could not open file for redirection! (0)");
	if (exe->file[1])
		if ((exe->fd[1] = open(exe->file[1], O_WRONLY | O_CREAT, 0600)) < 0)
			MFAIL("Could not open file for redirection! (1)");
	if (exe->file[2])
		if ((exe->fd[2] = open(exe->file[2], O_WRONLY | O_CREAT, 0600)) < 0)
			MFAIL("Could not open file for redirection! (2)");
	return (true);
}
