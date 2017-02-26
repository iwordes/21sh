/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 19:13:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/23 18:31:47 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** NOTE: NULL val may cause issues in the future.
*/

void	lx_pipe(t_token *tk, const char **str, bool *err)
{
	tk->type = TK_PIPE;
	tk->val = NULL;
	*str += 1;
	(void)err;
}
