/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_dec_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:24:33 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/29 17:24:34 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** NOTE: The XOR logic may not be accurate to printf.
*/

ssize_t	ft_asprintf_conv_dec_long(char **string, va_list arg, t_printer *p)
{
	if ((p->length & 12) != 0)
		p->length ^= 12;
	else
		p->length |= 4;
	return (ft_asprintf_conv_dec(string, arg, p));
}
