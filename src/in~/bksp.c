/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bksp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:38:40 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/06 18:08:45 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	in_bksp(t_in *in)
{
	if (in->i > 0)
	{
		in->i -= 1;
		ft_strcut(in->put, in->dex, 1);
		in_print(in);
	}
}
