/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_bksp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:38:40 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/03 13:19:37 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	in_bksp(char **cmd, size_t *i, size_t *l)
{
	if (*i > 0)
	{
		in_left(cmd, i, l);
		ft_strcut(*cmd, *i, 1);
		tm_clr_eos();
		tm_cur_save();
		ft_putvis(*cmd + *i);
		tm_cur_rest();
	}
	(void)l;
}
