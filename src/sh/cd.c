/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:42:49 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 13:58:53 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static bool	pls_chdir(char *path)
{
	if (chdir(path))
		return (false);
	env_set2("OLDPWD", env_get("PWD"));
	env_set2("PWD", path);
	return (true);
}

static bool	isdir(const char *path)
{
	struct stat	s;

	if (stat(path, &s))
		return (false);
	return (S_ISDIR(s.st_mode));
}

void		sh_cd(char **argv, int argc)
{
	ft_putstr("\e[95mcd\e[0m\n");
	if (argc > 2)
		ft_putstr("cd: Too many arguments.\n");
	else if (argc == 1)
		ft_putstr("cd: Not enough arguments.\n");
	else if (ft_strequ(argv[1], "-"))
		;
	else if (access(argv[1], F_OK))
		ft_putstr("cd: Path does not exist.\n");
	else if (!isdir(argv[1]))
		ft_putstr("cd: Path is not a directory.\n");
	else if (access(argv[1], R_OK))
		ft_putstr("cd: Cannot read directory.\n");
	else if (access(argv[1], X_OK))
		ft_putstr("cd: Cannot execute directory.\n");
	else if (!pls_chdir(argv[1]))
		ft_putstr("cd: Cannot chdir.\n");
	ft_putstr("\e[92mcd\e[0m\n");
}
