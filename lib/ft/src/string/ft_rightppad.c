/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rightppad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:53:32 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:15:10 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Prints a string, afterwards printing N instances of char pad until the given
** target has been met.
*/

void		ft_rightppad(const char *string, char pad, size_t target)
{
	size_t	i;

	if (string)
	{
		i = ft_strlen(string);
		ft_putstr(string);
		while (i < target)
		{
			ft_putchar(pad);
			i++;
		}
	}
}
