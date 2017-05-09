/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setkv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 09:29:04 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/23 21:22:40 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Set an alias based on a key-value pair as created by bi_alias.
** Return true if the alias was successfully set.
** Return false if no alias was set.
*/
/*
bool	alias_setkv(const char *kv)
{
	char		**alias;
	unsigned	i;

	if (!kv_check(kv))
		return (false);
	if ((alias = kv_split(kv)) == NULL)
		return (false);
	alias_set(alias[0], alias[1]);
	free(alias[1]);
	free(alias[0]);
	free(alias);
	return (true);
}
*/
