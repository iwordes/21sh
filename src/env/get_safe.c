/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_safe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:47:28 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/23 14:48:16 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Always returns a valid string.
*/

char	*env_get_safe(const char *key)
{
	char	*val;

	val = env_get(key);
	if (val == NULL)
		return ("");
	return (val);
}
