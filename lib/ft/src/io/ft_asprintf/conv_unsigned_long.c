/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_unsigned_long.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:03:34 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/29 17:03:42 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

ssize_t	ft_asprintf_conv_unsigned_long(char **string, va_list arg, t_printer *p)
{
	if ((p->length & 12) != 0)
		p->length ^= 12;
	else
		p->length |= 4;
	return (ft_asprintf_conv_unsigned(string, arg, p));
}
