/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 10:06:26 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/23 21:23:32 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*char	alias_add(const char *name, const char *cmd)
{
	unsigned	i;

	if (name[0] == 0 || ft_striequ(name, "alias"))
		return (0);
	i = 0;
	while (g_sh.alias[i] != NULL)
		i += 1;
	if (i + 1 >= g_sh.alias_len)
		alias_expand(i + 1);
	MGUARD(g_sh.alias[i] = (t_alias*)malloc(sizeof(t_alias)));
	MGUARD(g_sh.alias[i].name = ft_strdup(name));
	MGUARD(g_sh.alias[i].cmd = ft_strdup(cmd));
	g_sh.alias[i + 1] = NULL;
	return (1);
}*/
