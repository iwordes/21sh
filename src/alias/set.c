/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 09:57:33 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/23 21:22:34 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Create an alias to shorten the time needed to run a given command.
*/
/*
char	alias_set(const char *name, const char *cmd)
{
	unsigned	i;

	if (name[0] == 0 || ft_striequ(name, "alias"))
		return (0);
	i = ~0;
	while (g_sh.alias[i += 1] != NULL)
		if (ft_strequ(name, g_sh.alias[i].name))
		{
			if ((cmd = ft_strdup(cmd)) == NULL)
				return (0);
			free(g_sh.alias[i].cmd);
			g_sh.alias[i].cmd = cmd;
			return (1);
		}
	if (!alias_add(name, cmd))
		return (0);
	return (2);
}
*/
