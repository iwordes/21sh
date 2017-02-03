/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_sert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 10:31:27 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/03 10:43:20 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	in_sert(char **cmd, size_t *i, size_t *l, char *buff)
{
	ft_strins(*cmd, buff, *i);
	*i += ft_strlen(buff);
	ft_putstr(buff);
	tm_cur_save();
	ft_putstr(*cmd + *i);
	tm_cur_rest();
	(void)l;
}
