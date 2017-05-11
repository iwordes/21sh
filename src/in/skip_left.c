/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:22:36 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/10 19:08:02 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define LN in->ln[in->y]

void	in_skip_left(t_in *in)
{
	while (in->x > 0 && !ft_isspace(LN.ln[in->x - 1]))
		in_line_left(in);
	while (in->x > 0 && ft_isspace(LN.ln[in->x - 1]))
		in_line_left(in);
}
