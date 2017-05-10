/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 09:30:40 by iwordes           #+#    #+#             */
/*   Updated: 2017/01/01 20:38:54 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Things to watch out for:
** - What does printf do when given a prematurely NUL-terminated UTF-8 string?
*/
/*
** TODO
** - Truncate string to precision length
*/

ssize_t		ft_asprintf_conv_str_long(char **string, va_list arg, t_printer *p)
{
	uint32_t	*widestr;
	ssize_t		l;

	(void)p;
	if ((widestr = va_arg(arg, uint32_t*)) == NULL)
		widestr = (uint32_t*)L"(null)";
	if ((*string = (char*)ft_utf32to8(widestr)) == NULL)
		return (-1);
	l = ft_strlen(*string);
	if (p->prec >= 0)
	{
		l = MIN(l, p->prec);
		if (!IS_UTF8_ASCII((*string)[l]))
		{
			while (!IS_UTF8_HEAD((uint8_t)(*string)[l])
				&& !((*string)[l] > 0 && (*string)[l] <= 127)
				&& l > 0)
				l--;
			if (IS_UTF8_ASCII((*string)[l]) && (*string)[l] != 0)
				l++;
		}
		(*string)[MIN(l, p->prec)] = 0;
	}
	return ((ssize_t)l);
}
