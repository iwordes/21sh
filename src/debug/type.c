/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 19:37:18 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/26 19:42:19 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char	*debug_type(int type)
{
	if (type == TK_HDOC)
		return ("heredoc (<<)");
	if (type == TK_PIPE)
		return ("pipe (|)");
	if (type == TK_SEP)
		return ("separator (;)");
	if (type == TK_STR)
		return ("string");
	if (type == TK_STR1)
		return ("string ('')");
	if (type == TK_STR2)
		return ("string (\"\")");
	if (type == TK_RIN)
		return ("redirect (<)");
	if (type == TK_ROUT)
		return ("redirect (>)");
	if (type == TK_RAOUT)
		return ("redirect (>>)");
	if (type == TK_REDIR)
		return ("redirect");
	else
		return ("???");
}
