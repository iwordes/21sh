/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:22:20 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/10 19:11:25 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

#define LN in->ln[in->y]

void	in_skip_right(t_in *in)
{
	while (in->x < LN.len && !ft_isspace(LN.ln[in->x]))
		in_line_right(in);
	while (in->x < LN.len && ft_isspace(LN.ln[in->x]))
		in_line_right(in);
}
