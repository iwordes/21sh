/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str1_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 19:42:41 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/23 20:40:56 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	lx_str1_2(t_token *tk, const char **str, bool *err)
{
	size_t	i;
	char	q;

	i = 0;
	q = **str;
	*str += 1;
	tk->type = (q == '\'') ? TK_STR1 : TK_STR2;
	while ((*str)[i] != q && (*str)[i] != 0)
		i += 1;
	MGUARD(tk->val = ft_strsub(*str, 0, i));
	tk->val[i] = 0;
	*str += i;
	if (**str != 0)
		*str += 1;
	(void)err;
}
