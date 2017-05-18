/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ro1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:26:01 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/12 15:39:12 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

bool	ps_is_ro1(const char *tk)
{
	ITER(tk, ft_isdigit(*tk));
	tk += (*tk == '>');
	if (*tk == '&')
	{
		tk += 1;
		ITER(tk, ft_isdigit(*tk));
	}
	return (*tk == 0 || ft_isspace(*tk));
}
