/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:02:14 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/09 18:29:18 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	in_ctrl_v(t_in *in)
{
	if (in->clip != NULL)
	{
		if (in->s != 0)
		{
			// Erase selection
		}
		// Clipboard: Paste
		in->x += ft_strlen(in->clip);
		in_redraw(in);
	}
}
