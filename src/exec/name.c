/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:29:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/23 21:16:04 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static bool	valid_(const char *path)
{
	if (path == NULL)
		return (false);
	if (!access(path, R_OK | X_OK))
		return (false);
	if (fs_isdir(path))
		return (false);
	return (true);
}

static char	*find_name_(const char *name)
{
	char	*envpath;
	char	*path;
	char	*dir;
	size_t	l;

	l = 0;
	path = NULL;
	envpath = env_get_safe("PATH");
	while (*envpath != 0 && !valid_(path))
	{
		while (*envpath == ':')
			envpath += 1;
		l = ft_struntil(envpath, ':');
		BREAKIF(l == 0);
		MGUARD(dir = ft_strsub(envpath, 0, l));
		if (fs_search(dir, name))
			path = fs_join(dir, name);
		free(dir);
	}
	return (path);
}

int			exec_name(t_cmd *cmd)
{
	return (exec_wait(exec_name_async(cmd)));
}

pid_t		exec_name_async(t_cmd *cmd)
{
	char	*path;
	pid_t	pid;

	path = find_name_(cmd->argv[0]);
	if (path == NULL)
	{
		ft_eprintf("sh: %s: No such command\n", cmd->argv[0]);
		return (-1);
	}
	pid = exec_path_async(cmd, path);
	free(path);
	return (pid);
}
