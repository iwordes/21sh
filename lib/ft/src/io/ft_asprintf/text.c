/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:35:12 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/14 08:40:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Return a copy of all characters in the given format specifier until the next
** '%' character.
*/

ssize_t		ft_asprintf_text(const char **fmt, char **state)
{
	ssize_t	length;

	length = ft_struntil(*fmt, '%');
	*state = ft_strsub(*fmt, 0, length);
	if (*state == NULL)
		return (-1);
	*fmt += length;
	return (length);
}
