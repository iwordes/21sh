/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 16:20:31 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 14:56:13 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define FAIL(E) { g_mn.err = E; return (true); }

static bool	error_(const char *exe)
{
	struct stat		s;

	if (ft_strchr(exe, '/'))
	{
		if (access(exe, F_OK))
			FAIL("Path does not exist.");
		if (stat(exe, &s))
			FAIL("Cannot stat file.");
		if ((s.st_mode & S_IFREG) == 0)
			FAIL("Path is not a file.");
		if (access(exe, R_OK))
			FAIL("File cannot be read.");
		if (access(exe, X_OK))
			FAIL("File cannot be executed.");
	}
	return (false);
}

static bool	try_match(const char *exe, const char *path)
{
	struct stat	s;
	char		buff[4096];
	size_t		l1;
	size_t		l2;

	buff[0] = 0;
	l1 = ft_strlen(exe);
	l2 = ft_struntil(path, ':');
	if (l1 + l2 + 2 >= 4096)
		return (false);
	ft_strncat(buff, path, l2);
	ft_strcat(buff, "/");
	ft_strcat(buff, exe);
	if (access(buff, R_OK | X_OK) || stat(buff, &s))
		return (false);
	return (S_ISREG(s.st_mode));
}

static bool	find_(const char *exe, char **ret)
{
	char	*path;
	size_t	o;

	o = 0;
	path = env_gets("PATH");
	if (path[0] == 0)
		path = ".";
	while (path[o])
	{
		if (try_match(exe, path + o))
		{
			*ret = path + o;
			return (true);
		}
		ITER(o, path[o] && path[o] != ':');
		o += (path[o] != 0);
	}
	g_mn.err = "Could not find executable.";
	return (false);
}

static char	*uninit_(const char *exe, const char *path)
{
	static char	join[4096];
	size_t		l1;
	size_t		l2;

	l1 = ft_strlen(exe);
	l2 = ft_struntil(path, ':');
	if (l1 + l2 + 2 > 4096)
		return (NULL);
	bzero(join, 4096);
	ft_strncpy(join, path, l2);
	ft_strcat(join, "/");
	ft_strcat(join, exe);
	return (join);
}

char		*sh_meta_path(const char *exe)
{
	char	*path;

	if (error_(exe))
		return (NULL);
	if (ft_strchr(exe, '/'))
		return ((char*)exe);
	if (!find_(exe, &path))
		return (NULL);
	return (uninit_(exe, path));
}
