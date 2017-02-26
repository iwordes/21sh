/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 10:37:56 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/05 12:36:24 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	update_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	var_setkey("OLDPWD", env_get("PWD"));
	env_setkey("PWD", cwd);
	free(cwd);
}
