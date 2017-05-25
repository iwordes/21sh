/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ri2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:03:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/25 15:46:49 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define IS_END(C) (C == 0 || ft_isspace(C))

bool	ps_is_ri2(const char *tk)
{
	if (tk[0] != '<' || tk[1] != '<')
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
