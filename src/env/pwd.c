/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 10:13:22 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/05 10:34:02 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Update PWD with the current directory and OLDPWD with the old PWD.
*/

void	env_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	var_setkey("OLDPWD", env_get("PWD"));
	env_setkey("PWD", cwd);
	free(cwd);
}
