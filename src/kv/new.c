/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:07:21 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/03 19:12:58 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char	*kv_new(const char *key, const char *val)
{
	if (key == NULL || key[0] == 0)
		return (NULL);
	if (val == NULL)
		val = "";
	return (FT_VSTRJOIN(key, "=", val));
}
