/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_octal_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 09:45:49 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/27 09:50:20 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

ssize_t	ft_asprintf_conv_octal_long(char **string, va_list arg, t_printer *p)
{
	if ((p->length & 12) != 0)
		p->length ^= 12;
	else
		p->length |= 4;
	return (ft_asprintf_conv_octal(string, arg, p));
}
