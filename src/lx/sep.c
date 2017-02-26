/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 10:47:39 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/23 20:40:09 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	lx_sep(t_token *tk, const char **str, bool *err)
{
	while (**str != 0 && **str == ';')
	{
		while (**str == ';')
			*str += 1;
		while (ft_isspace(**str))
			*str += 1;
	}
	tk->type = TK_SEP;
	tk->val = NULL;
	(void)err;
}
