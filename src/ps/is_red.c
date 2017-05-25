/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 13:44:48 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/25 13:47:09 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define ARR(C) (C == '<' || C == '>')

bool	ps_is_red(const char *str)
{
	ITER(str, ft_isdigit(*str));
	if (!ARR(*str))
		return (false);
	str += 1;
	return (!ARR(*str) || *str == str[-1]);
}
