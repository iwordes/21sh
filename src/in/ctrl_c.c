/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:59:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/05/09 18:00:21 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	in_ctrl_c(t_in *in)
{
	if (in->s == 0)
		in->cancel = true;
	else
	{
		// Clipboard: Copy
	}
}
