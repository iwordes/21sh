/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_ln.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:25:52 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/07 19:13:42 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Move up or down a line in the editor.
**
** NOTE: More logic will be needed to handle proper index carry-over.
*/

void	in_up_ln(t_in *in)
{
	if (in->y > 0)
	{
		in->y -= 1;
		in_print(in);
	}
}
