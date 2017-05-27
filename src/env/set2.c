/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 12:47:18 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 13:17:27 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

bool	env_set2(const char *key, const char *val)
{
	char	*tmp;
	size_t	l1;
	size_t	l2;
	bool	o;

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
		return (o);
	}
	return (false);
}
