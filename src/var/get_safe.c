/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_safe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:14:21 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/06 13:16:00 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char	*var_get_safe(const char *key)
{
	char	*val;

	val = env_get(key);
	if (val == NULL)
		val = var_get(key);
	if (val == NULL)
		MGUARD(val = ft_strnew(0));
	return (val);
}
