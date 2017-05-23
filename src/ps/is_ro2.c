/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ro2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:02:24 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/22 15:56:16 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define IS_END(C) (C == 0 || ft_isspace(C))

bool	ps_is_ro2(const char *tk)
{
	ITER(tk, ft_isdigit(*tk));
	if (tk[0] != '>' || tk[1] != '>')
		return (false);
	tk += 2;
	if (*tk == '&')
	{
		tk += 1;
		if (*tk == '-' && IS_END(tk[1]))
			return (true);
		ITER(tk, ft_isdigit(*tk));
		return (IS_END(*tk));
	}
	return (true);
}
