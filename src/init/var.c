/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:22:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/03 19:28:46 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	init_var(void)
{
	MGUARD(g_sh.var = (char**)ft_memalloc(sizeof(char*) * (VAR_LEN + 1)));
	g_sh.var_len = VAR_LEN;
}
