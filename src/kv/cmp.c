/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:09:30 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/04 11:22:15 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Compare the key part of two key(/value pair)s.
** 0: No similarity.
** 1: Match, kv1 is a key.
** 2: Match, kv1 is a key/value pair.
*/

char	kv_cmp(const char *kv1, const char *kv2)
{
	while (*kv1 != 0 && *kv1 != '=' && *kv1 == *kv2)
	{
		kv1 += 1;
		kv2 += 1;
	}
	if (*kv1 == 0 && *kv2 == '=')
		return (2);
	else if (*kv1 == '=' && *kv2 == '=')
		return (1);
	return (0);
}
