/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 13:56:15 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/31 20:37:32 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

ssize_t	ft_asprintf_conv_char_long(char **string, va_list arg, t_printer *p)
{
	wchar_t		c;

	c = va_arg(arg, wchar_t);
	if ((*string = ft_strnew(4)) == NULL)
		return (-1);
	else if ((*(wchar_t*)*string = ft_utf8_encode(c)) == -1)
		return (-1);
	if (c == 0)
		return (1);
	return ((ssize_t)ft_strlen(*string));
	(void)p;
}
