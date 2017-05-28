/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 13:45:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 17:47:57 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define TK ps->tk[i]

static bool	pls_insert(char **str)
{
	char	*tmp;

	if ((tmp = ft_strjoin(env_gets("HOME"), *str + 1)))
	{
		free(*str);
		*str = tmp;
	}
	return (tmp != NULL);
}

bool	ps_home(t_ps *ps)
{
	uint32_t	i;

	i = 0;
	while (i < ps->tk_len)
	{
		if (TK.type == TKT_NONE && TK.str[0] == '~')
			return (pls_insert(&TK.str));
		i += 1;
		while (i < ps->tk_len && (TK.flag & TKF_ADJ))
			i += 1;
	}
	return (true);
}
