/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 09:56:48 by iwordes           #+#    #+#             */
/*   Updated: 2017/03/18 09:57:58 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

bool	in_sel_left(t_in *in)
{
	in->sel -= 1;
	in_print(in);
	return (false);
}
