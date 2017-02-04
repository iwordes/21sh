/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:03:42 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/04 11:15:39 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** All inputs must have at least 1 character and an '=' sign.
** 0: Not set.
** 1: Updated.
** 2: Created.
*/

char	var_set(const char *var)
{
	size_t	i;

	if (env_get(var) != NULL)
		return (env_set(var));
	i = ~0L;
	while (g_sh.var[i += 1] != NULL)
		if (kv_cmp(var, g_sh.var[i]))
		{
			free(g_sh.var[i]);
			if ((g_sh.var[i] = ft_strdup(var)) == NULL)
				return (0);
			break ;
		}
	if (g_sh.var[i] != NULL)
		return (1);
	var_grow(i);
	if ((g_sh.var[i] = ft_strdup(var)) == NULL)
		return (0);
	return (2);
}
