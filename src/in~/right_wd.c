/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_wd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:52:34 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/06 17:56:23 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Move the cursor right to the next non-whitespace.
*/

void	in_right_wd(t_in *in)
{
	while (in->i < in->cl && !ft_isspace(in->put[in->i]))
		in_right(in);
	while (in->i < in->cl && ft_isspace(in->put[in->i]))
		in_right(in);
}
