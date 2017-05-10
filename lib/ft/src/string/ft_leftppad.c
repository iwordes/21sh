/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leftppad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:53:58 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:15:06 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Prints a string, first printing N instances of char pad, until the string is
** of greater or equal length compared to the target.
*/

void		ft_leftppad(const char *string, char pad, size_t target)
{
	size_t	i;
	size_t	l;

	if (string)
	{
		i = 0;
		l = ft_strlen(string);
		while (i < l - target)
		{
			ft_putchar(pad);
			i++;
		}
		ft_putstr(string);
	}
}
