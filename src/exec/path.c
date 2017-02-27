/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:32:07 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 14:35:46 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static bool	valid_(const char *path)
{
	if (access(path, F_OK) == -1)
		ft_eprintf("sh: %s: No such file or directory\n", path);
	else if (access(path, R_OK | X_OK) == -1)
		ft_eprintf("sh: %s: Permission denied\n", path);
	else if (fs_isdir(path))
		ft_eprintf("sh: %s: Is a directory\n", path);
	else
		return (true);
	return (false);
}

int			exec_path(t_cmd *cmd, const char *path)
{
	return (exec_wait(exec_path_async(cmd, path)));
}

pid_t		exec_path_async(t_cmd *cmd, const char *path)
{
	pid_t	pid;

	if ((pid = fork()) != 0)
		return (pid);
	redir(cmd->redir);
	if (valid_(path))
		if (execve(path, cmd->argv, g_sh.env) == -1)
			ft_eprintf("sh: %s: execve failed\n", path);
	exit(1);
}
