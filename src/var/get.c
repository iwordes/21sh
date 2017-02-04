/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 09:55:16 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/04 11:15:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char	*var_get(const char *var)
{
	size_t	i;

	i = ~0L;
	while (g_sh.var[i += 1] != NULL)
		if (kv_cmp(g_sh.var[i], var))
			return (ft_strchr(g_sh.var[i], '=') + 1);
	return (env_get(var));
}
