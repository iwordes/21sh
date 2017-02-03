/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_bksp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:38:40 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/03 10:44:08 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	in_bksp(char **cmd, size_t *i, size_t *l)
{
	if (*i > 0)
	{
		*i -= 1;
		ft_strcut(*cmd, *i, 1);
		tm_left();
		tm_clr_eos();
		tm_cur_save();
		ft_putstr(*cmd + *i);
		tm_cur_rest();
	}
	(void)l;
}
