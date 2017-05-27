/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 12:45:58 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/27 13:42:41 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

char	*env_get(const char *key)
{
	uint32_t	i;

	i = ~0;
	while (++i < g_mn.env_len)
		if (env_cmp(key, g_mn.env[i]))
			return (g_mn.env[i] + ft_strlen(key) + 1);
	return (NULL);
}
