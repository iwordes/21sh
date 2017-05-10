/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 16:42:47 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 19:14:55 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Uses modulo arithmetic to convert any number to a string of the proper base.
** - Limited to the range of base-2 to base-62 (alphanumeric range)
** - base-36 is the maximum range of case-insensitive numbers. (0-9, Aa-Bb)
** - Does not pad numbers with zeroes. Use
*/
/*
** Why...
** ===
** - do you use while (1)?
**   A: It's loop that runs at least once before it may or may not break out.
**   That's quite similar to how some other looping control statements work...
** - do you use --place?
**   A: It takes less lines and causes me to *not* overwrite the strnew \0.
** - do you use CHRMAP? What even is that, anyway?
**   A: CHRMAP is my macro that provides the proper character set for my base
**   functions, like itoa_base. I've defined it in my header.
*/

char		*ft_itoa_base(intmax_t integer, char base)
{
	char	*string;
	int		place;

	if (base >= 2 && base <= 64)
	{
		place = ft_intlen_base(integer, base);
		if (integer < 0 && base == 10)
			place++;
		NULL_GUARD(string = ft_strnew(place));
		if (integer < 0 && base == 10)
			string[0] = '-';
		while (TRUE)
		{
			string[--place] = BASE64[ft_absolute(integer % base)];
			integer /= base;
			if (integer == 0)
				break ;
		}
		return (string);
	}
	return (NULL);
}
