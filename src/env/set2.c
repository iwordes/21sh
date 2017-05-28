/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 12:47:18 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 18:09:42 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

bool	env_set2(const char *key, const char *val)
{
	char	*tmp;
	size_t	l1;
	size_t	l2;
	bool	o;

	ft_printf("\e[95menv_set2\e[0m\n");

	l1 = ft_strlen(key);
	l2 = ft_strlen(val);
	tmp = MALT(char, l1 + l2 + 2);
	if (tmp)
	{
		ft_strcpy(tmp, key);
		ft_strcat(tmp, "=");
		ft_strcat(tmp, val);
		o = env_set(tmp);
		free(tmp);

		if (o)
			ft_printf("\e[92menv_set2\e[0m\n");
		else
			ft_printf("\e[91menv_set2\e[0m\n");
		return (o);
	}
	ft_printf("\e[91menv_set2\e[0m\n");
	return (false);
}
