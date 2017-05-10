/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:09:59 by iwordes           #+#    #+#             */
/*   Updated: 2017/02/03 13:13:58 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putvis(const char *str)
{
	char	invis[2];

	invis[0] = '^';
	while (*str != 0)
	{
		if (!ft_iscntrl(*str))
			write(1, str, 1);
		else
		{
			invis[1] = (*str + 64) & 127;
			write(1, invis, 2);
		}
		str += 1;
	}
}
