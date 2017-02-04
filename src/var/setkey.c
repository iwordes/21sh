/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setkey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:06:52 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/03 19:17:55 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** 0: Not set.
** 1: Updated.
** 2: Created.
*/

char	var_setkey(const char *key, const char *val)
{
	char	*kv;
	char	o;

	if ((kv = kv_new(key, val)) == NULL)
		return (0);
	o = var_set(kv);
	free(kv);
	return (o);
}
