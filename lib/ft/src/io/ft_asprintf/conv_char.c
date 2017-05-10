/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:28:13 by iwordes           #+#    #+#             */
/*   Updated: 2016/12/31 20:37:13 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

ssize_t		ft_asprintf_conv_char(char **string, va_list arg, t_printer *p)
{
	if ((p->length & 4) != 0)
		return (ft_asprintf_conv_char_long(string, arg, p));
	if ((*string = ft_strnew(1)) == NULL)
		return (-1);
	(*string)[0] = (char)va_arg(arg, int);
	return (1);
}
