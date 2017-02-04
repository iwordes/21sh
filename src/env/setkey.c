/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setkey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 10:23:50 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/04 10:24:46 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** 0: Not set.
** 1: Updated.
** 2: Created.
*/

char	env_setkey(const char *key, const char *val)
{
	char	*kv;
	char	o;

	if ((kv = kv_new(key, val)) == NULL)
		return (0);
	o = env_set(kv);
	free(kv);
	return (o);
}
