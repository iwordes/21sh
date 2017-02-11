/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 10:34:29 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/05 12:35:43 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	env_list(void)
{
	size_t	i;
	size_t	l;

	i = ~0L;
	while (g_sh.env[i += 1] != NULL)
	{
		l = ft_struntil(g_sh.env[i], '=');
		ft_printf("\e[97m%.*s\e[0m='%s'", l, g_sh.env[i], g_sh.env[i] + l + 1);
	}
}
