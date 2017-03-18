/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_wd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:50:17 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/06 17:55:32 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
** Move the cursor left to the next non-whitespace.
*/

void	in_left_wd(t_in *in)
{
	while (in->i > 0 && !ft_isspace(in->put[in->i - 1]))
		in_left(in);
	while (in->i > 0 && ft_isspace(in->put[in->i - 1]))
		in_left(in);
}
